Problem statement Break Down :

1. we have to implement the RandomizedSet class:
2. RandomizedSet() Initializes the RandomizedSet object.
3. bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
4. bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
5. int getRandom() Returns a random element from the current set of elements

Solution : 

class RandomizedSet {

private:
   vector<int> nums;
   unordered_map<int,int> val_to_index;

public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
    
       if(val_to_index.find(val) != val_to_index.end()){
          return false;
       }

       nums.push_back(val);
       val_to_index[val] = nums.size()-1;
       return true;

    }
    
    bool remove(int val) {

        if(val_to_index.find(val) == val_to_index.end()){
            return false;
        }

        int index = val_to_index[val];

        int lastElement = nums.back();
        nums[index] = lastElement;
        val_to_index[lastElement] = index;

        nums.pop_back();
        val_to_index.erase(val);

        return true;
        
    }
    
    int getRandom() {
        
        int random_index = rand() % nums.size();
        return nums[random_index];
    }
};

Time Complexity : O(1)
Space complexity : O(n)
