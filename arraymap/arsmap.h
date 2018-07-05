#ifndef ARSMAP
#define ARSMAP
#include <vector>


template<typename T,typename K>
class arrays_map {
public:
    arrays_map(T* index,size_t sizeT, K* value, size_t sizeK)
     //: indices{index, index + sizeT}, values{value, value + sizeK}
    {
         if(sizeT<sizeK)
         {
            //std::cout<<"az indexek hossza kissebb mint az ertekeke" << std::endl;
            for( int idx = 0; idx < sizeT; ++idx)
            {
              indices.push_back(index[idx]);
              values.push_back(value[idx]);
            }

         } else {
            //std::cout<<"az indexek hossza nagyobb mint az ertekeke" << std::endl;
            for( int idx = 0; idx < sizeK; ++idx)
            {
                indices.push_back(index[idx]);
                values.push_back(value[idx]);
            }
         }
    }

    int size() const
    {
        if(indices.size()<values.size())
        {
           //std::cout<<"size: "<< indices.size();
           return indices.size();
        }
        //std::cout<<"size: "<< values.size();
        return values.size();
    }

    K at(T elem) const
    {
        int idx=0;
        bool got = false;
        while((idx<indices.size()) && (got == false))
        {
            if(elem == indices.at(idx))
            {
                got = true;
            } else {
                ++idx;
            }
        }
        //std::cout<<"at "<< elem << "elem is " << values.at(idx);
        return values.at(idx);
    }

    K& operator[] (T elem)
    {
        int idx=0;
        bool got = false;
        while((idx<indices.size()) && (got == false))
        {
            if(elem == indices.at(idx))
            {
                got = true;
            } else {
                ++idx;
            }
        }
        return values.at(idx);
    }

    //konstanson konstans tagfügvényhez konstans visszatérésssel
    const K& operator[] (T elem) const
    {
        int idx=0;
        bool got = false;
        while((idx<indices.size()) && (got == false))
        {
            if(elem == indices.at(idx))
            {
                got = true;
            } else {
                ++idx;
            }
        }
        return values.at(idx);
    }

private:
    std::vector<T> indices;
    std::vector<K> values;
    //K* values;
};


#endif // ARSMAP
