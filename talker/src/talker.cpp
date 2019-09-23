/*
Copyright (c) 2019, ROSIN-project
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
 * This tutorial demonstrates simple sending of messages over the ROS system 
 * using the rxros interface
 */

#include <rxros/rxros.h>
#include <std_msgs/String.h>

using namespace rxcpp::operators;
using namespace rxros::operators;

std_msgs::String mk_msg (const std::string& s)  // the missing factory
{ 
    std_msgs::String msg;
    msg.data = std::string(s);
    return msg;
};


int main(int argc, char **argv)
{
  rxros::init(argc, argv, "talker");
  const std::string hello = "hello world ";

  rxcpp::observable<>::interval (std::chrono::milliseconds (1000)) 
    | map ([&](int i) 
        { return mk_msg(hello + std::to_string(i)); })
    | tap ([](const std_msgs::String& msg) 
        { ROS_INFO ("%s", msg.data.c_str()); })
    | publish_to_topic<std_msgs::String> ("/chatter", 1000);

  rxros::spin();
  return 0;
}
