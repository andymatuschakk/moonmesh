//
// Created by admin on 2025/12/15.
//

#ifndef EVM_RPC_CPP_ETH_PARAM_TYPE_H
#define EVM_RPC_CPP_ETH_PARAM_TYPE_H
#include <string>

#include "eth.h"


ETH_PARAM(eth_estimateGas,
std::vector<std::string> datas;
    reflect::reflect_status parse(const nlohmann::json & j) {
        return reflect::Deserialize(j,datas);
    }
);

ETH_RET(eth_estimateGas,
    std::string gas;
    nlohmann::json make() const {
        nlohmann::json j;
        j=gas;
        return j;
    }
);



ETH_PARAM(eth_getBalance,
    std::vector<std::string> hashs;
    reflect::reflect_status parse(const nlohmann::json & j) {
        return reflect::Deserialize(j,hashs);
    }
);

ETH_RET(eth_getBalance,
    std::string balance;
    nlohmann::json make() const {
        nlohmann::json j;
        j = balance;
        return j;
    }
);

ETH_NO_PARAM(eth_chainId,
    std::string id;
    nlohmann::json make() const {
        nlohmann::json j;
        j=id;
        return j;}
);

ETH_NO_PARAM(net_version,
    std::string version;
    nlohmann::json make() const {
        nlohmann::json j;
        j=version;
        return j;}
);

ETH_NO_PARAM(eth_blockNumber,
    std::string number;
    nlohmann::json make() const {
        nlohmann::json j;
        j=number;
        return j;}
);


ETH_NO_PARAM(eth_gasPrice,
    std::string price;
    nlohmann::json make() const {
        nlohmann::json j;
        j=price;
        return j;}
);




ETH_PARAM(eth_getTransactionCount,
    std::vector<std::string> hashs;
    reflect::reflect_status parse(const nlohmann::json & j) {
       return reflect::Deserialize(j,hashs);
   });
ETH_RET(eth_getTransactionCount,
    std::string count;
    nlohmann::json make() const{
        nlohmann::json j;
        j=count;
        return j;}
    );


ETH_PARAM(eth_sendRawTransaction,
    std::vector<std::string> datas;
    reflect::reflect_status parse(const nlohmann::json & j) {
       return reflect::Deserialize(j,datas);
   });
ETH_RET(eth_sendRawTransaction,
    std::string hash;
    nlohmann::json make()const {
        nlohmann::json j;
        j=hash;
        return j;}
    );


ETH_PARAM(eth_call,
    std::string from;
    std::string value;
    std::string gasPrice;
    std::string data;
    std::string to;
    std::string gas;
    REFLECT(from,value,gasPrice,data,to,gas)
    reflect::reflect_status parse(const nlohmann::json & j) {
        return reflect::Deserialize(j,*this);
    }
);

ETH_RET(eth_call,
    std::string res;
    nlohmann::json make()const {
        nlohmann::json j;
        j=res;
        return j;
    }
);









ETH_PARAM(eth_getCode,
    std::vector<std::string> datas;
    reflect::reflect_status parse(const nlohmann::json & j) {
        return reflect::Deserialize(j,datas);
    }
);


ETH_RET(eth_getCode,
    std::string hash;
    nlohmann::json make()const {
        nlohmann::json j;
        j=hash;
        return j;
    }
);




ETH_PARAM(eth_getTransactionReceipt,
    std::vector<std::string> datas;
    reflect::reflect_status parse(const nlohmann::json & j) {
        return reflect::Deserialize(j,datas);
    }
    
);

ETH_RET(eth_getTransactionReceipt,
        std::string blockHash;
        std::string blockNumber; 
        std::string contractAddress;                                                                     // string of the address if it was created
        std::string cumulativeGasUsed; 
        std::string effectiveGasPrice; 
        std::string from; 
        std::string gasUsed; 
        nlohmann::json logs; // logs as returned by getFilterLogs, etc.
        std::string logsBloom;                                                                                                    // 256 byte bloom filter
        std::string status; 
        nlohmann::json to; 
        std::string transactionHash; 
        std::string transactionIndex; 
        std::string type; 
        REFLECT(blockHash, blockNumber, contractAddress, cumulativeGasUsed, effectiveGasPrice, from, gasUsed, logs, logsBloom, status, to, transactionHash, transactionIndex, type)

            nlohmann::json make() const {
        nlohmann::json j;
       reflect::Serialize(*this,j);
        return j; });

ETH_PARAM(eth_getBlockByNumber,
   std::string number;
   bool isfull;
   REFLECT(number,isfull)
   reflect::reflect_status parse(const nlohmann::json & j) {
       reflect::reflect_status ret;

       try {
           j[0].get_to(number);
           j[1].get_to(isfull);
       }catch (std::exception & e) {
           ret.ok=false;
           ret.error=e.what();
           return ret;
       }
       return ret;
    }
);

ETH_PARAM(eth_getBlockByHash,
   std::string hash;
   bool isfull;
   REFLECT(hash,isfull)
   reflect::reflect_status parse(const nlohmann::json & j) {
       reflect::reflect_status ret;

       try {
           j[0].get_to(hash);
           j[1].get_to(isfull);
       }catch (std::exception & e) {
           ret.ok=false;
           ret.error=e.what();
           return ret;
       }
       return ret;
    }
);

ETH_RET(eth_getBlockByHash,
    std::string difficulty;
    std::string extraData;
    std::string gasLimit;
    std::string gasUsed;
    std::string gasPrice;
    std::string hash;
    std::string logsBloom;
    std::string miner;
    std::string mixHash;
    std::string nonce;
    std::string number;
    std::string parentHash;
    std::string receiptsRoot;
    std::string sha3Uncles;
    std::string size;
    std::string stateRoot;
    std::string timestamp;
    std::string totalDifficulty;
    std::string transactions;
    std::string transactionsRoot;
    std::string uncles;
    REFLECT(difficulty,extraData,gasLimit,gasUsed,
        gasPrice,hash,logsBloom,miner,mixHash,nonce,number,parentHash,receiptsRoot,sha3Uncles,size,stateRoot,timestamp,totalDifficulty,transactions,transactionsRoot,uncles)

    nlohmann::json make() const{
        nlohmann::json j;
       reflect::Serialize(*this,j);
        return j;
    }
);

ETH_RET(eth_getBlockByNumber_hash,
    std::string hash;
    bool isfull;
    nlohmann::json make()const {
        nlohmann::json j=nlohmann::json::array();
        j.push_back(hash);
        j.push_back(isfull);
        return j;
    }
);

ETH_RET(eth_getBlockByNumber_block,
std::string difficulty;
std::string extraData;
std::string gasLimit;
std::string gasUsed;
std::string hash;
std::string logsBloom;
std::string miner;
std::string mixHash;
std::string nonce;
std::string number;
std::string parentHash;
std::string receiptsRoot;
std::string sha3Uncles;
std::string size;
std::string stateRoot;
std::string timestamp;
std::string totalDifficulty;
std::vector<std::string> transactions;
std::string transactionsRoot;
std::vector<std::string> uncles;
// std::string baseFeePerGas;
// std::vector<std::string> withdrawals;
// std::string withdrawalsRoot;
// std::string blobGasUsed;
// std::string excessBlobGas;
// std::string parentBeaconBlockRoot;
// std::string requestsHash;

REFLECT(difficulty,extraData,gasLimit,gasUsed,hash,logsBloom,miner,mixHash,nonce,number,parentHash,receiptsRoot,
    sha3Uncles,size,stateRoot,timestamp,totalDifficulty,transactions,transactionsRoot,uncles/*baseFeePerGas,
    withdrawals,withdrawalsRoot,blobGasUsed,excessBlobGas,parentBeaconBlockRoot,requestsHash*/)
nlohmann::json make()const {
    nlohmann::json j;
    reflect::Serialize(*this,j);
    return j;
}
);


ETH_NO_PARAM(web3_clientVersion,
    std::string version;
    nlohmann::json make() const {
        nlohmann::json j;
        j=version;
        return j;
}
 );

ETH_PARAM(eth_getTransactionByHash, std::string hash;  REFLECT(hash) reflect::reflect_status parse(const nlohmann::json &j) {
       reflect::reflect_status ret;

       try {
           j[0].get_to(hash);
       }catch (std::exception & e) {
           ret.ok=false;
           ret.error=e.what();
           return ret;
       }
       return ret; }
);

ETH_RET(eth_getTransactionByHash,
    std::string blockHash;
    std::string blockNumber;
    std::string from ;
    std::string gas;
    std::string gasPrice;
    std::string hash;
    std::string input;
    std::string nonce;
    std::string to;
    std::string transactionIndex;
    std::string value;
    std::string v;
    std::string r;
    std::string s;
    std::string type;
    std::string maxFeePerGas;
    std::string maxPriorityFeePerGas;
    REFLECT(blockHash,blockNumber,from,gas,gasPrice,hash,input,nonce,to,transactionIndex,value,v,r,s,type,maxFeePerGas,maxPriorityFeePerGas)

    nlohmann::json make() const {
        nlohmann::json j;
       reflect::Serialize(*this,j);
        return j;
    }
);


ETH_NO_PARAM(eth_accounts,
    std::vector<std::string> accounts;
    REFLECT(accounts)
    nlohmann::json make() const {
        nlohmann::json j;
        reflect::Serialize(*this,j);
        return j;
    }
);


#endif //EVM_RPC_CPP_ETH_PARAM_TYPE_H