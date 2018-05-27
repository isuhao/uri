// Copyright 2016-2017 Glyn Matthews.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt of copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <fstream>
#include <gtest/gtest.h>
#include <network/uri/detail/uri_parse.hpp>

// http://formvalidation.io/validators/uri/

std::vector<std::string> create_urls(const std::string &filename) {
  std::vector<std::string> urls;
  std::ifstream ifs(filename);
  if (!ifs) {
    throw std::runtime_error("Unable to open file: " + filename);
  }
  for (std::string url; std::getline(ifs, url);) {
    if (url.front() != '#') {
      urls.push_back(url);
    }
  }
  return urls;
}

// All valid URLs in the list should pass
class test_valid_urls : public ::testing::TestWithParam<std::string> {};

INSTANTIATE_TEST_CASE_P(uri_parse_test, test_valid_urls,
                        testing::ValuesIn(create_urls("valid_urls.txt")));

TEST_P(test_valid_urls, urls_are_valid) {
  auto input = GetParam();
  std::cout << input << std::endl;
  auto result = network::detail::parse(input);
  EXPECT_TRUE(result.success);
}
