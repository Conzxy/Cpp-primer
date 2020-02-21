>《C++ primer 5th》p305:
<br>向一个vector、string或deque插入元素会使所有指向容器的迭代器、引用和指针失效<br>
```cpp
vector<string>    ivec;
vector<string>::iterator   iter=ivec.begin();
while(cin>>word)
    iter=ivec.insert(iter,word);    //效果和push_front一样

//以下是错误的，因为此时iter已经失效
vector<string>    ivec;
vector<string>::iterator   iter=ivec.begin();
while(cin>>word)
    ivec.insert(iter,word);    //错误，经过一轮的insert后iter已失效，无法调用
```
vector使用的连续分配的内存，而迭代器则是指针的简单包装（迭代器代表着容器中的地址），
当进行insert或push操作时，预先申请的内存空间不够，则需要重新申请更大的新内存空间，然后将元素move或copy过去，导致指针指向的内存已不再存储该vector的元素了；
而进行erase操作时，删除元素后面的所有元素都需要向前移一位，这时指向的内存是未知的。
因此，vector元素一旦有变化，索性就让迭代器失效来保证正确性。
