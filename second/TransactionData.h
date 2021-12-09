//
// Created by mrworldend on 09/12/2021.
//

#ifndef BLOCKCHAINDEV_TRANSACTIONDATA_H
#define BLOCKCHAINDEV_TRANSACTIONDATA_H

struct TransactionData
{
    double amount;
    std::string senderKey;
    std::string receiverKey;
    time_t timestamp;

    TransactionData();
    TransactionData(double amt, std::string sender, std::string receiver, time_t time)
    {
        amount = amt;
        senderKey = sender;
        receiverKey = receiver;
        timestamp = time;
    };
};

#endif //BLOCKCHAINDEV_TRANSACTIONDATA_H
