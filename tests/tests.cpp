#include <catch2/catch_test_macros.hpp>

extern "C" {
#include "list.h"
#include "max.h"
#include <stdlib.h>
}

// TEST_CASE("test") { REQUIRE(1 == 1); }

TEST_CASE("max", "[max]") {
  {
    int numbers[] = {5, 10, 20, 6, 10, -1, 9};
    REQUIRE(max(numbers, 7) == 20);
  }
  {
    int numbers[] = {5, 1, 4};
    REQUIRE(max(numbers, 3) == 5);
  }
  {
    int numbers[] = {-2};
    REQUIRE(max(numbers, 1) == -2);
  }
  {
    int numbers[] = {-2, -5, -42, -67, -100, -1};
    REQUIRE(max(numbers, 1) == -1);
  }
  {
    int numbers[] = {0, 0, 0, 0, 0, 0, 0, 0};
    REQUIRE(max(numbers, 8) == 0);
  }
}

TEST_CASE("size", "[list]") {
  node *l = (node *)malloc(sizeof(node));
  l->next = NULL;
  REQUIRE(size(l) == 0);

  l->next = (node *)malloc(sizeof(node));
  l->next->next = NULL;
  l->next->data = 10;

  REQUIRE(size(l) == 1);

  l->next->next = (node *)malloc(sizeof(node));
  l->next->next->next = NULL;
  l->next->next->data = 20;

  REQUIRE(size(l) == 2);
}

TEST_CASE("largest", "[list]") {
  node *l = (node *)malloc(sizeof(node));
  l->data = 0;
  l->next = NULL;

  l->next = (node *)malloc(sizeof(node));
  l->next->next = NULL;
  l->next->data = 0;
  REQUIRE(largest(l) == 0);

  for (int i = 10; i > 0; i--) {
    node *p = l;
    while (p->next != NULL) {
      p = p->next;
    }
    p->next = (node *)malloc(sizeof(node));
    p = p->next;
    p->next = NULL;
    p->data = i;
  }
  REQUIRE(largest(l) == 10);

  l->next->next->next->data = 100;

  REQUIRE(largest(l) == 100);
}
