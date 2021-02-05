/*************************************************************************\

                             C O P Y R I G H T

  Copyright 2003 Image Synthesis Group, Trinity College Dublin, Ireland.
                        All Rights Reserved.

  Permission to use, copy, modify and distribute this software and its
  documentation for educational, research and non-profit purposes, without
  fee, and without a written agreement is hereby granted, provided that the
  above copyright notice and the following paragraphs appear in all copies.


                             D I S C L A I M E R

  IN NO EVENT SHALL TRININTY COLLEGE DUBLIN BE LIABLE TO ANY PARTY FOR 
  DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING,
  BUT NOT LIMITED TO, LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE 
  AND ITS DOCUMENTATION, EVEN IF TRINITY COLLEGE DUBLIN HAS BEEN ADVISED OF 
  THE POSSIBILITY OF SUCH DAMAGES.

  TRINITY COLLEGE DUBLIN DISCLAIM ANY WARRANTIES, INCLUDING, BUT NOT LIMITED 
  TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
  PURPOSE.  THE SOFTWARE PROVIDED HEREIN IS ON AN "AS IS" BASIS, AND TRINITY 
  COLLEGE DUBLIN HAS NO OBLIGATIONS TO PROVIDE MAINTENANCE, SUPPORT, UPDATES,
  ENHANCEMENTS, OR MODIFICATIONS.

  The authors may be contacted at the following e-mail addresses:

          Gareth_Bradshaw@yahoo.co.uk    isg@cs.tcd.ie

  Further information about the ISG and it's project can be found at the ISG
  web site :

          isg.cs.tcd.ie

\**************************************************************************/

/*
    Array with a free list
*/
#ifndef _FREE_ARRAY_H_
#define _FREE_ARRAY_H_

#include "Array.h"
#include "LinkedList.h"

template <class T> class FreeArray : public Array<T>{
  private:
    struct FreeNode{
      int i;
      FreeNode *next, *prev;
      };
    LinkedList<FreeNode> freeList;

  public:
    //  free up an item
    void freeItem(int i){
      CHECK_DEBUG2((unsigned int)i < (unsigned int)size, "Index Array Out of Bounds, Size : %d, Index : %d", size, i);
      //  add the node to the free list
      FreeNode *newNode = new FreeNode;
      freeList.initNode(newNode);

      newNode->i = i;
      freeList.addNode(newNode);

      index(i).free = true;
      }

    //  get a free item
    int addIndex(){
      FreeNode *node = freeList.getFirst();
      if (!node){
        int newI = Array<T>::addIndex();

        index(newI).free = false;

        return newI;
        }
      else{
        int newI = node->i;

        freeList.removeNode(node);
        delete node;

        index(newI).free = false;
        return newI;
        }
      }

    T& addItem(){
      int s = addIndex();
      return index(s);
      }
};

#endif