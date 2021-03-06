/*********************                                                        */
/*! \file skolem_lemma.h
 ** \verbatim
 ** Top contributors (to current version):
 **   Andrew Reynolds
 ** This file is part of the CVC4 project.
 ** Copyright (c) 2009-2021 by the authors listed in the file AUTHORS
 ** in the top-level source directory and their institutional affiliations.
 ** All rights reserved.  See the file COPYING in the top-level source
 ** directory for licensing information.\endverbatim
 **
 ** \brief The skolem lemma utility
 **/

#include "cvc4_private.h"

#ifndef CVC4__THEORY__SKOLEM_LEMMA_H
#define CVC4__THEORY__SKOLEM_LEMMA_H

#include "expr/node.h"
#include "theory/trust_node.h"

namespace CVC4 {
namespace theory {

/**
 * A skolem lemma is a pair containing a trust node repreresenting a lemma
 * and the skolem it is for. A common example would be the trust node proving
 * the lemma:
 *    (ite C (= k A) (= k B))
 * and the skolem k.
 *
 * Skolem lemmas can be used as a way of tracking the relevance of a lemma.
 * They can be used for things like term formula removal and preprocessing.
 */
class SkolemLemma
{
 public:
  SkolemLemma(TrustNode lem, Node k) : d_lemma(lem), d_skolem(k)
  {
    Assert(lem.getKind() == TrustNodeKind::LEMMA);
  }
  /** The lemma, a trust node of kind LEMMA */
  TrustNode d_lemma;
  /** The skolem associated with that lemma */
  Node d_skolem;
};

}  // namespace theory
}  // namespace CVC4

#endif /* CVC4__THEORY__SKOLEM_LEMMA_H */
