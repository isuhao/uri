// Copyright 2018 Glyn Matthews.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt of copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <gtest/gtest.h>
#include <skyr/ipv4_address.hpp>


TEST(ipv4_address_tests, zero_test) {
  auto instance = skyr::ipv4_address(0);
  EXPECT_EQ("0.0.0.0", instance.to_string());
}

TEST(ipv4_address_tests, loopback_test) {
  auto instance = skyr::ipv4_address(0x7f000001);
  EXPECT_EQ("127.0.0.1", instance.to_string());
}

TEST(ipv4_address_tests, parse_zero_test) {
  auto address = std::string("0.0.0.0");
  auto instance = skyr::parse_ipv4_address(address);
  ASSERT_TRUE(instance);
  EXPECT_EQ(0, instance.value().address());
}

TEST(ipv4_address_tests, parse_loopback_test) {
  auto address = std::string("127.0.0.1");
  auto instance = skyr::parse_ipv4_address(address);
  ASSERT_TRUE(instance);
  EXPECT_EQ(0x7f000001, instance.value().address());
}
