/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on May 23, 2021, 1:30 PM
 */
using namespace std;
#include <cstdlib>
#include <list>
#include <string>
#include <map>
#include <iostream>



class CLRUCache{
public:
    string get(int key){
        map<int, string>::iterator it; 
        it = this->hashMap.find(key);
        if(it!=hashMap.end()){
            return (*it).second;
        }
        return "";
    }
    //Test API  to ensure  that the code is working. You Dont need this API for implementing LRU Cache
    int cacheSize(){
        return this->dblPrtList.size();
    }
    int put(int key, string value){
        //We still have space to accomodate in the map
        if(this->cacheSize()< this->maxCap){
            this->dblPrtList.push_front(key);
            this->hashMap[key]= value;
        }
        else{
            //We need to remove the least recent ly used and make space for the new one
            //first get the key in the dblPrtList's lastitem from rear end;
            int keyToDelete = *(this->dblPrtList.end());
            //delete this key from the hashmap
            this->hashMap.erase(keyToDelete);
            
            //delete this key from the dbl link list also
            this->dblPrtList.pop_back();

            //Insert the new element to the begining of the dblPrtList
            this->dblPrtList.push_front(key);

            //Add this new element to the hashmap
            this->hashMap[key] = value;  
        }
        return 0;
    }
    CLRUCache(int maxCapacity){
        this->maxCap = maxCapacity;
    }
    virtual ~CLRUCache(){
        
    }
private:
    map<int, string> hashMap;
    list<int> dblPrtList;
    int maxCap;
};


/*
 * 
 */
int main(int argc, char** argv) {
    CLRUCache lruCache(5);
    cout<<"\n Initial Cache Size " << lruCache.cacheSize();
    lruCache.put(1,"India");
    cout<<"\n Cache Size After inserting India: " << lruCache.cacheSize();
    
    lruCache.put(2,"America");
    cout<<"\n Cache Size After inserting America: " << lruCache.cacheSize();

    cout<<"\n Value at Key 1 is :  " << lruCache.get(1);
    
    lruCache.put(3,"Germany");
    cout<<"\n Cache Size After inserting America: " << lruCache.cacheSize();
 
    
    lruCache.put(4,"Australia");
    cout<<"\n Cache Size After inserting America: " << lruCache.cacheSize();
    
    lruCache.put(5,"NewZealand");
    cout<<"\n Cache Size After inserting America: " << lruCache.cacheSize();
    
    lruCache.put(6,"France");
    cout<<"\n Cache Size After inserting America: " << lruCache.cacheSize();
    
    lruCache.put(7,"UK");
    cout<<"\n Cache Size After inserting America: " << lruCache.cacheSize();
    
    return 0;
}

