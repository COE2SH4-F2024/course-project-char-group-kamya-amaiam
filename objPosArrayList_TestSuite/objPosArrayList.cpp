#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList(){ //constructor

    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos [ARRAY_MAX_CAP];
    
}


objPosArrayList::~objPosArrayList() { //destructor

    delete[] aList;

}


objPosArrayList::objPosArrayList(const objPosArrayList &sList){ //copy constructor

    listSize = sList.listSize;
    arrayCapacity = sList.arrayCapacity;
    aList = new objPos [arrayCapacity];

    for (int i = 0; i<listSize; i++){
        aList[i] = sList.aList[i];
    }

}


objPosArrayList& objPosArrayList::operator=(const objPosArrayList &sList){ //copy assignment operator

    if(this != &sList) {
        this->arrayCapacity = sList.arrayCapacity;
        this->listSize = sList.listSize;        
    }

    for (int i = 0; i< this->listSize; i++){
        aList[i] = sList.aList[i];
    }

}


int objPosArrayList::getSize() const {

    return listSize;

}


void objPosArrayList::insertHead(objPos thisPos) {

    if (listSize == arrayCapacity){
        //cout << "array is full" << endl;
        return;
    }

    for (int i=listSize; i>0; i--){
        aList[i] = aList[i-1];
    }

    aList[0] = thisPos;
    listSize++;
    
}


void objPosArrayList::insertTail(objPos thisPos) {

    aList[listSize] = thisPos;
    listSize++;

}


void objPosArrayList::removeHead() {

     for (int i=0; i<listSize-2; i++){
        aList[i] = aList[i+1];
    }

    listSize--;
    
}


void objPosArrayList::removeTail() {

    if (listSize == 0){
        //cout << "list is empty" << endl;
        return;
    }

    listSize--;
    
}


objPos objPosArrayList::getHeadElement() const {
    
    return aList[0].getObjPos();

}


objPos objPosArrayList::getTailElement() const {

    return aList[listSize-1].getObjPos();
    
}


objPos objPosArrayList::getElement(int index) const {

    return aList[index].getObjPos();
    
}