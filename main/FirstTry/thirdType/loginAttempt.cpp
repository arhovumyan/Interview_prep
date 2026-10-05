/*
per user login rate limiter
make a function that
acceps user id and string timestamps returnign bool
allowed window is 5 attempts at most in any 60 second window
true is allowed false if not

you will receive the user id and the requests.

approach
you can make a hashmap with id as key and a queue as value
function example
std::unordered_map<int,std::queue<int>> storage

bool storer(int id, std::queue<int> timestamps){
    bool allowed = true;

    while (!timestamps.empty()){
        int timestamp = timestamps.front();
        timestamps.pop();

        while (!storage[id].empty() &&
        timestamp - storage[id].front() >= 60) {
            storage[id].pop();
        }
        if (storage[id].size() >= 5) allowed = false; continue;

        storage[id].push(timestamp);

        return allowed;
    }
}


*/