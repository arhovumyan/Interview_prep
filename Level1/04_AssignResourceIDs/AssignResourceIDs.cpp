class Resource {
public:
    int assigingID(std::vector<std::pair<int,int>> reservations){
        int nestID = 0;
        // each machine will have its start and end time
        // when we iterate through the reservations and one of the machine's reservation
        // start time is earlier than their end tiem, then we ive it a new unique ID
        std::vector<int> result;

        // you will store the time and ID in here
        std::priority_queue<std::pair<int,int>, 
        std::vector<std::pair<int,int>>,
        std::greater<std::pair<int,int>>> minHeap;
        std::sort(reservations.begin(), reservations.end());

        for (int i = 0; i < reservations.size(); i++){
            int start = reservations[i].first;
            int end = reservations[i].second;
            
            while (!minHeap.empty() && minHeap.top().first <= start){
                
            }
                // Need to understand this minHeap fully, then itll work
        }
    }
};