//
// Created by taoyongji on 2020/9/17.
//

#ifndef MYPORJECTFORCLION_LIST_H
#define MYPORJECTFORCLION_LIST_H
template<typename T>
class List{
 public:
  virtual ~List(){}
  virtual bool add(T e) = 0;
  virtual T get(int index) = 0;
  virtual T remove(int index) = 0;
};

#endif //MYPORJECTFORCLION_LIST_H
