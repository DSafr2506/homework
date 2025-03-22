#include "library.hpp"

namespace template_library {

    void EventScheduler::add_event(int time, const std::string& event) {
        events[time] = event;
        time_queue.push(time);
    }

    std::string EventScheduler::process_next() {
        if (time_queue.empty()){
            return "";
        }
        else{
            auto temp = events.find(time_queue.top()) -> second;
            time_queue.pop();
            return temp;
        }
    }
}
