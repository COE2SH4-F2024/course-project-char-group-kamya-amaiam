#include "objPosArrayList.h"



objPosArrayList::objPosArrayList() //constructor
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos [ARRAY_MAX_CAP];
}


objPosArrayList::~objPosArrayList() //destructor
{
    delete[] aList;
}


objPosArrayList::objPosArrayList(const objPosArrayList &sList) //copy constructor
{
    listSize = sList.listSize;
    arrayCapacity = sList.arrayCapacity;
    aList = new objPos [arrayCapacity];

    for (int i = 0; i<listSize; i++){
        aList[i] = sList.aList[i];
    }
}


objPosArrayList& objPosArrayList::operator=(const objPosArrayList &sList) //copy assignment operator
{
    if(this != &sList) 
    {
        this->arrayCapacity = sList.arrayCapacity;
        this->listSize = sList.listSize;        
    }

    for (int i = 0; i< this->listSize; i++)
    {
        aList[i] = sList.aList[i];
    }
}


int objPosArrayList::getSize() const //returns list size 
{
    return listSize;
}


void objPosArrayList::insertHead(objPos thisPos) //insert a head position
{
    if (listSize == arrayCapacity){
        return;
    }

    for (int i=listSize; i>0; i--){
        aList[i] = aList[i-1];
    }

    aList[0] = thisPos;
    listSize++;
}


void objPosArrayList::insertTail(objPos thisPos) //inserts a tail position
{
    aList[listSize] = thisPos;
    listSize++;
}


void objPosArrayList::removeHead() //removes head position
{
    for (int i=0; i<listSize-2; i++)
    {
        aList[i] = aList[i+1];
    }

    listSize--;
}


void objPosArrayList::removeTail() //removes tail position 
{
    if (listSize == 0){
        return;
    }

    listSize--;
}


objPos objPosArrayList::getHeadElement() const //returns what's at head position 
{    
    return aList[0].getObjPos();
}


objPos objPosArrayList::getTailElement() const  //returns what's at tail position 
{
    return aList[listSize-1].getObjPos();   
}


objPos objPosArrayList::getElement(int index) const //returns the what's at the element position 
{
    return aList[index].getObjPos();   
}
