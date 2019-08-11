# ******************************************************
# Author       : Vigoroushui
# Last modified: 2019-08-11 17:16
# Email        : vigoroushui@gmail.com
# Filename     : LRUCache.cc
# Description  : watch the question in problem.md
# ******************************************************

/*整体思路：采用c++STL中的unordered_map和list来建立hash映射，执行get操作时，将该pair对移到list的最前端。
 *执行put操作时，如果缓存区已满，就删除list最后一个pair对，否则可以插入。*/
class LRUCache {
public:
    LRUCache(int capacity)
    :_capicity(capacity)
    {}
    int get(int key)
    {
        auto iterator=_m.find(key);
        if(iterator==_m.end())
            return -1;
        //查找到目标元素后讲元素移到list的头部
        int val=iterator->second->second;
        _list.erase(iterator->second);
        _list.push_front(make_pair(key,val));
        //另一种将元素移到list头部的方法
        //_list.splice(_list.begin(),_list,iterator->secont);
        _m[key]=_list.begin();
        return iterator->second->second;
    }
    void put(int key, int value)
    {
        auto iterator=_m.find(key);
        if(iterator!=_m.end())
            _list.erase(iterator->second);
        _list.push_front(make_pair(key,value));
        _m[key]=_list.begin();
        //淘汰节点
        if(_list.size()>_capicity){
            int key=_list.back().first;
            _m.erase(key);
            _list.pop_back();
        }
    }
private:
    int _capicity;
    list<pair<int,int>> _list;
    unordered_map<int,list<pair<int,int>>::iterator> _m;//存储list的位置信息
};