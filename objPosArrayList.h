#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList;
        int listSize;
        int arrayCapacity;

    public:
        objPosArrayList(); //constructor (1/4)
        ~objPosArrayList(); //destructor (2/4)
        objPosArrayList(const objPosArrayList &sList); //copy constructor (3/4)
        objPosArrayList& operator=(const objPosArrayList &sList); //copy assignment constructor (4/4)


        int getSize() const;

        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        objPos getHeadElement() const;
        objPos getTailElement() const;
        objPos getElement(int index) const;

        //ITERATION 3
        bool checkFoodConsumption();
        void increasePlayerLength();
        bool checkSelfCollision();
    
};

#endif