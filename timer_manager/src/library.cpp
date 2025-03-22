#include "library.hpp"

namespace template_library {

    void EventScheduler::add_event(int time, const std::string& event) {
        events[time] = event;
        event_times.push(time);
    }

    std::string EventScheduler::process_next() {
        if (event_times.empty()) {
            return "";
        }

        int next_time = event_times.top();
        event_times.pop();

        std::string next_event = events[next_time];
        events.erase(next_time);

        return next_event;
    }
}