/**
 * @file arena_immobile_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION3_SRC_ARENA_IMMOBILE_ENTITY_H_
#define PROJECT_ITERATION3_SRC_ARENA_IMMOBILE_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief An immobile entity in the Arena.
 *
 * Immobile entities cannot move, and therefore do not need to override the
 * TimestepUpdate() function.
 */
class ArenaImmobileEntity : public ArenaEntity {
 public:
  /**
   * @brief ArenaImmobileEntity's constructor.
   *
   * @param radius The radius of the entity (as it is circular).
   * @param pos The initial position of the entity.
   * @param color The color of the entity as shown on the screen.
   */
  ArenaImmobileEntity(double radius,
                      const Position &pos,
                      const Color &color) :
      ArenaEntity(radius, pos, color) {}
};

NAMESPACE_END(csci3081);

#endif /* PROJECT_ITERATION3_SRC_ARENA_IMMOBILE_ENTITY_H_ */
