//redo

#include<bits/stdc++.h>
enum class shout
{
  unknown,
  bark,
  purr
};

struct animal
{
  animal(std::string n = std::string(), shout t = shout::unknown) : name(n), shoutingTraits(t) {}

  // properties
  std::string name;
  shout shoutingTraits;
};

struct dog : public animal
{
  dog(std::string n = std::string()) : animal(n, shout::bark) {}
};

struct cat : public animal
{
  cat(std::string n = std::string()) : animal(n,shout::purr) {}
};

class adopt;
std::ostream& operator<<(std::ostream& out, const adopt& center);

class adopt
{
  public:
  bool enqueue(const animal& animal)
  {
    if(animal.shoutingTraits == shout::unknown) {
      throw std::runtime_error("only dogs and cats accepted");
    }
    animals.push_back(animal);
    return true; //implement size restrictions
  }

  bool dequeOldestTrait(shout trait, animal& a)
  {
    assert(trait != shout::unknown);

    for(std::list<animal>::iterator it = animals.begin() ; it != animals.end() ; it++) {
      if(it->shoutingTraits == trait) {
        a = *it;
        animals.erase(it);
        return true;
      }
    }
    return false;
  }

  bool dequeAnimal(animal& a, shout trait = shout::unknown)
  {
    if(animals.empty()) {
      throw std::runtime_error("Sheleter not opened yet");
    }
    if(trait == shout::unknown){
      a = animals.front();
      animals.pop_front();
      return true;
    }
    return dequeOldestTrait(trait, a);
  }

  bool dequeDog(dog& dog) //reference to derived type
  {
     return dequeAnimal(dog, shout::bark);
  }

  bool dequeCat(cat& cat)
  {
     return dequeAnimal(cat, shout::purr);
  }

  friend std::ostream& operator<<(std::ostream& out, const adopt& center);

  private:
  std::list<animal> animals;
};

std::ostream& operator<<(std::ostream& out, const adopt& center)
{
  out << "Adoption Center animals queue => ";
  for(auto a : center.animals) {
    out << "(" << a.name << ","<< (int)a.shoutingTraits << "), ";
  }
  out << std::endl;
  return out;
}

void createCenter(adopt& adoptionCenter)
{
  dog d0("dog0");
  dog d1("dog1");
  dog d2("dog2");
  dog d3("dog3");
  dog d4("dog4");
  dog d5("dog5");

  cat c0("cat0");
  cat c1("cat1");
  cat c2("cat2");
  cat c3("cat3");
  cat c4("cat4");
  cat c5("cat5");


  adoptionCenter.enqueue(d0);

  adoptionCenter.enqueue(c1);
  adoptionCenter.enqueue(c0);

  adoptionCenter.enqueue(d3);
  adoptionCenter.enqueue(d4);

  adoptionCenter.enqueue(c5);

  adoptionCenter.enqueue(d1);

  adoptionCenter.enqueue(c3);

  adoptionCenter.enqueue(d2);

  adoptionCenter.enqueue(c4);
  adoptionCenter.enqueue(c2);

  adoptionCenter.enqueue(d5);

  std::cout << adoptionCenter;
}

void unitTests(adopt& adoptionCenter)
{
  std::cout << "\nRemoving dog (d0 should be removed)" << std::endl;
  dog tmp;
  if(!adoptionCenter.dequeDog(tmp)) {
    std::cout << "dog removal failed" <<std::endl;
  }
  std::cout << adoptionCenter;


  std::cout << "\nRemoving one more dog (d3 should be removed)" << std::endl;
  if(!adoptionCenter.dequeDog(tmp)) {
    std::cout << "dog removal failed" <<std::endl;
  }
  std::cout << adoptionCenter;

  std::cout << "\nRemoving cat (c1 should be removed)" << std::endl;
  cat tCat;
  if(!adoptionCenter.dequeCat(tCat)) {
    std::cout << "cat removal failed" <<std::endl;
  }
  std::cout << adoptionCenter;


  std::cout << "\nRemoving other cat (c0 should be removed)" << std::endl;
  if(!adoptionCenter.dequeCat(tCat)) {
    std::cout << "cat removal failed" <<std::endl;
  }
  std::cout << adoptionCenter;
}

int main()
{
  adopt adoptionCenter;

  std::cout << "AdoptionCenter should be empty" << std::endl;
  std::cout << adoptionCenter;
  std::cout << "Removing on empty queue" << std::endl;
  animal a;
  try {
    std::cout << adoptionCenter.dequeAnimal(a) << std::endl;
  } catch (const std::runtime_error& e) {
    std::cout << e.what() << std::endl;
  }

  createCenter(adoptionCenter);

  unitTests(adoptionCenter);

  return 0;
}