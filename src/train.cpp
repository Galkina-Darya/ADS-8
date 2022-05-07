// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() :countOp(0), first(nullptr), tail(nullptr) {}

Train::Cage *Train::create(bool light) {
  Cage *temp = new Cage;
  temp->light = light;
  temp->next = nullptr;
  temp->prev = nullptr;
  return temp;
}

void Train::addCage(bool light) {
  if (first && tail) {
    tail->next = create(light);
    tail->next->prev = tail;
    tail = tail->next;
    if (!first->prev) {
      first->prev = tail;
    }
    if (!first->next) {
      tail->next = first;
    }
  } else {
      first = create(light);
      tail = first;
    }
}
int Train::getLenght() {
  first->light = true;
  Cage *temp = first;
  int lenght = 0, tmpCount = 0;
  while (true) {
    ++countOp;
    ++tmpCount;
    temp = temp->next;
    if (temp->light) {
      int tmp = tmpCount;
      temp->light = false;
      for (int i = tmpCount; tmpCount; tmpCount--, countOp++) {
        temp = temp->prev;
      }
      if (!temp->light) {
        light = tmp;
        break;
      }
    }
  }
  return lenght;
}
int Train::getOpCount() {
  return countOp;
}
