//
// Created by admin on 2025/12/15.
//

#ifndef EVM_RPC_CPP_RPC_H
#define EVM_RPC_CPP_RPC_H
#include "eth.h"
#include "eth_rpc_json_def.h"
#include "utils/base64.h"
ETH_FUNC(eth_estimateGas);
ETH_FUNC(eth_chainId);
ETH_FUNC(eth_getCode);
ETH_FUNC(net_version);
ETH_FUNC(eth_blockNumber);
ETH_FUNC(eth_gasPrice);
ETH_FUNC(eth_getBalance);
ETH_FUNC(eth_getTransactionCount);
ETH_FUNC(eth_sendRawTransaction);
ETH_FUNC(eth_getTransactionReceipt);
ETH_FUNC(eth_call);
ETH_FUNC(eth_getBlockByNumber);
ETH_FUNC(eth_getBlockByHash);
ETH_FUNC(web3_clientVersion);
ETH_FUNC(eth_getTransactionByHash);
ETH_FUNC(eth_accounts);
#endif //EVM_RPC_CPP_RPC_H