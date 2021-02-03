#include <iostream>
#include <filesystem>
#include <fstream>
#include <pthread.h>
#include <vector>
#include <sstream>
#include "calc.h"

std::string res_path;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t address_lock = PTHREAD_MUTEX_INITIALIZER;

struct Process{
    operation op;
    double a;
    double b;
};
std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

Process string_to_process(std::string str) {
    Process res;
    auto data = split(str, ' ');
    res.op = static_cast<operation>(std::stoi(data[0]));
    res.a = std::stod(data[1]);
    res.b = std::stod(data[2]);
    return res;
}


void *action(void *arg) {
    std::ifstream file;
    std::string path = std::string(*((std::string *) arg));
    pthread_mutex_unlock(&address_lock);
    file.open(path);
    std::string raw((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());
    file.close();
    auto pr = string_to_process(raw);
    auto res = "result of test with path " + path + " = " + calc(pr.a, pr.b, pr.op);
    std::ofstream res_file;
    pthread_mutex_lock(&lock);
    res_file.open(res_path , std::ios::app | std::ios::out);
    res_file << res << std::endl;
    pthread_mutex_unlock(&lock);

    return nullptr;
}

int main(int argc, char **argv) {
    if (argc < 3)
        return 0;

    std::string catalog(argv[1]);
    res_path = std::string(argv[2]);

    std::vector<pthread_t> pid_list;

    for (const auto &entry : std::filesystem::directory_iterator(catalog)) {
        pthread_t pid;
        pthread_mutex_lock(&address_lock);
        auto path = entry.path().string();
        pthread_create(&pid, nullptr, action, (void *) &path);
        pid_list.push_back(pid);
    }

    void *res;

    for (auto pid : pid_list) {
        pthread_join(pid, &res);
    }

    return 0;
}