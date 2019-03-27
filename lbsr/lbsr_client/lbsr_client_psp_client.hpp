/*
 * Copyright 2018 Yamana Laboratory, Waseda University
 * Supported by JST CREST Grant Number JPMJCR1503, Japan.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE‐2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LBSR_CLIENT_PSP_CLIENT_HPP
#define LBSR_CLIENT_PSP_CLIENT_HPP

#include <memory>
#include <vector>
#include <string>
#include <stdsc/stdsc_thread.hpp>

namespace lbsr_client
{
class PSPParam;

/**
 * @brief Provides client for PSP.
 */
template <class T = PSPParam>
class PSPClient : public stdsc::Thread<T>
{
    using super = stdsc::Thread<T>;

public:
    PSPClient(const char* host, const char* port);
    virtual ~PSPClient(void);

    void start(T& param);
    void wait_for_finish(void);
    void get_result(std::vector<long>& resutls);

private:
    virtual void exec(T& args,
                      std::shared_ptr<stdsc::ThreadException> te) const;

    struct Impl;
    std::shared_ptr<Impl> pimpl_;
};

struct PSPParam
{
    std::string pubkey_filename = "pukey.txt";
};

} /* namespace lbsr_client */

#endif /* LBSR_CLIENT_PSP_CLIENT_HPP */
