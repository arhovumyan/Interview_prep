/* 
create a class
in private
craete a static const that would store max available request at once
make a priority queue that will store all the requests
in public
make an addRequest that will push time and id to the main minHeap
make a bool allow function that accepts the time and id
create a temp vector of pair storing ints 
start a while loop that runs until the main minHeap is empty
    store the top value of main minheap in an auto current 
    check wether the time window is less than 10 
        if it is, then check whether the current id is the same as the passed in id
            if it is, add 1 to the user request count
            then push the top value that we stored in the auto current into the temp minHeap

*/