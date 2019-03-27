/* STUDENTS:  DO NOT EDIT THIS FILE.  INSTEAD, MODIFY YOUR OWN PROJECT
 * CODE TO FIT THE SPECIFICATION GIVEN BY THE TESTS IN THIS FILE.
 *
 * If you DO modify it, we overwrite it with a fresh version from our repo
 * when grading, so you can't use it to fudge the tests anyway.
 *
 * This file is used by the CS3081W auto-grading system.
 *
 * Please note, the assessment tests for grading, will use the same include
 * files, class names, and function names for accessing students' code that you
 * find in this file.  So students, if you write your code so that it passes
 * these feedback tests, you can be assured that the auto-grader will at least
 * be able to properly link with your code.
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "../src/color.h"
#include "../src/obstacle.h"

static_assert(std::is_base_of<csci3081::ArenaImmobileEntity, csci3081::Obstacle>::value,
              "FAIL: Obstacle must be immobile");

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
#ifdef OBSTACLE_TEST

TEST(Obstacle, Sanity) {
  Position pos(1, 1);
  csci3081::Color color(0, 0, 0, 1);
  csci3081::Obstacle c0(1.0, pos, color);
  csci3081::Obstacle c1(1.0, pos, color);

  EXPECT_EQ(c0.get_name(), "Obstacle0") <<
      "FAIL: Bad name for obstacle";
  EXPECT_EQ(c1.get_name(), "Obstacle0") <<
      "FAIL: Bad name for obstacle";
}

TEST(Obstacle, TimestepUpdate) {
  Position pos(1, 1);
  csci3081::Color color(0, 0, 0, 1);
  csci3081::Obstacle c(1.0, pos, color);

  for (size_t i = 0; i < 10; ++i) {
    c.TimestepUpdate(1);
    EXPECT_EQ(c.get_pos(), pos) << "FAIL: obstacle moved";
  } /* for(i..) */
}

#endif /* OBSTACLE_TEST */