class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    MedianFinder() {

    }
    
    void addNum(int num) {
        if(minHeap.size()<maxHeap.size())
            minHeap.push(num);
        else{
            maxHeap.push(num);
        }    
        if(minHeap.size()>0 && maxHeap.size()>0 && minHeap.top() < maxHeap.top()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size())return (minHeap.top()+maxHeap.top())/2.0;
        else if(minHeap.size()>maxHeap.size())return minHeap.top();
        return maxHeap.top();
    }
};
// 1 2 3 4 
// min 4 3
// max 1 2