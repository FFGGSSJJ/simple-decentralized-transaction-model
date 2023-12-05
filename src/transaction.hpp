#include <thread>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <map>
#include <mutex>
#include <queue>
#include <algorithm>

#include "rmulticast.hpp"

static std::map<std::string, int> accounts;

int deposit_handler()
{
    return EXIT_SUCCESS;
}

int transfer_handler()
{
    return EXIT_SUCCESS;
}

void transaction_recv(int node_id)
{
    std::string loggername = "logs/transaction_logger";
    loggername.push_back((char)('0'+node_id));
    loggername.append(".txt");
    std::ofstream logger(loggername, std::ios::out | std::ios::trunc);
    while (true) {
        if (transaction_queue.empty()) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            continue;
        }

        /* handle incomin transaction */
        logger << "[INFO]: transaction coming::" << transaction_queue.front().substr(4) << std::endl;
        transaction_queue.pop_front();
    }
    return;
}