//
// Created by admin on 2025/12/15.
//

#ifndef EVM_RPC_CPP_ETH_H
#define EVM_RPC_CPP_ETH_H
#include "utils/reflect_struct/reflect_struct.h"


struct eth_req_header {
    
    std::string id;
    std::string jsonrpc;
    std::string method;
    REFLECT(jsonrpc,method);
    reflect::reflect_status parse(const nlohmann::json & j) {
      reflect::reflect_status ret;
        try {
            uint64_t nid;
            if (j["id"].is_number()) {
                j["id"].get_to(nid);
                id=std::to_string(nid);
            }else if (j["id"].is_string()) {
                j["id"].get_to(id);
            }

        }catch (std::exception & e) {
            ret.ok = false;
            ret.error=e.what();
            return ret;
        }
        ret=reflect::Deserialize(j,*this);
        return ret;
    }
};



struct eth_errors {
    std::string code;
    std::string message;
    std::string data;
    bool ok=true;
    REFLECT(code,message,data)

    nlohmann::json to_json()const   {
        nlohmann::json res;
       auto st= reflect::Serialize(*this,res);
        return res;
    }
};


struct eth_res_s{
    nlohmann::json id;
    std::string jsonrpc="2.0";
    REFLECT(id,jsonrpc)
    template<typename T>
    nlohmann::json make(const T &res) const {
        nlohmann::json ret;
        ret["id"]=id;
        ret["jsonrpc"]=jsonrpc;
        ret["result"]=res.make();
        return ret;
    }
};

struct eth_res_header {
    // std::string id = "1";
    // std::string jsonrpc = "2.0";
    // REFLECT(id,jsonrpc)
    nlohmann::json make_result(const nlohmann::json &res, eth_errors & e) const {
        nlohmann::json ret;
        if (!e.ok) {
            ret["error"]=e.to_json();
            return ret;
        }
       return res;
        //return ret;
    }

};



inline  reflect::reflect_status ParseHeader(const nlohmann::json &j,eth_req_header & req) {

    auto st=  reflect::Deserialize(j,req);
    if (!st.ok) {
        return st;
    }
    if (!j.contains("param")) {
        return {"not found param",false};
    }
    return {"",true};
}


#define ETH_PARAM(struct_name,...)\
struct struct_name{ \
    nlohmann::json req; \
     constexpr static  const  char * method=#struct_name;\
    __VA_ARGS__\
}

#define ETH_RET(struct_name,...)\
struct struct_name##_ret{\
    eth_res_s ret_header;\
    __VA_ARGS__ \
}


#define ETH_NO_PARAM(struct_name,...)\
struct struct_name{ \
constexpr static  const  char * method=#struct_name;\
    nlohmann::json req; \
reflect::reflect_status parse(const nlohmann::json & j) {\
    return {"",true};\
}\
};\
struct struct_name##_ret{\
eth_res_s ret_header;\
__VA_ARGS__ \
}




// struct eth_estimateGas{
//     eth_req_header req;
//     constexpr static  const  char * method="eth_estimateGas";
//     std::string from;
//     std::string value;
//     std::string gasPrice;
//     std::string data;
//     std::string to;
//     std::string gas;
//     REFLECT(from,value,gasPrice,data,to,gas);
// };

// struct eth_estimateGas_ret {
//     std::string gas;
//     nlohmann::json make() {
//         nlohmann::json j;
//         j=gas;
//         return j;
//     }
// };



#define ETH_FUNC(STRUCT_NAME)\
    nlohmann::json fun_##STRUCT_NAME(const STRUCT_NAME& req,eth_errors & e)


#define ETH_LAMDA(STRUCT_NAME)\
{ #STRUCT_NAME,[](const  nlohmann::json& req)->nlohmann::json {\
    STRUCT_NAME req_obj;\
    req_obj.req=req; \
    req_obj.parse(req["params"]);\
    eth_res_header res;\
    eth_errors er;\
    nlohmann::json res_json;\
    res_json=fun_##STRUCT_NAME(req_obj, er);\
    res_json=res.make_result(res_json,er);\
    return res_json;\
}}\


#endif //EVM_RPC_CPP_ETH_H