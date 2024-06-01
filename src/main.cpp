#include <iostream>
#include "ari_utils.h"


int main() {
    std::string server_url = "http://192.168.0.132:8088";
    std::string user = "asterisk";
    std::string password = "secret";

    // Create a bridge
    std::string bridge_id = create_bridge(server_url, user, password);
    std::cout << "Bridge created with ID: " << bridge_id << std::endl;

    // Create a new channel to the target extension (inactive)
    std::string new_channel_id = create_channel(server_url, "SIP/7002", "7002", "default", 1, "my-stasis-app", user, password);
    std::cout << "New channel created with ID: " << new_channel_id << std::endl;

    // Active channel ID (replace this with the actual active channel ID)
    std::string active_channel_id = "1717230609.0";

    // Add the active channel to the bridge
    add_channel_to_bridge(server_url, bridge_id, active_channel_id, user, password);
    std::cout << "Active channel " << active_channel_id << " added to bridge " << bridge_id << std::endl;

    // Add the new channel to the bridge
    add_channel_to_bridge(server_url, bridge_id, new_channel_id, user, password);
    std::cout << "New channel " << new_channel_id << " added to bridge " << bridge_id << std::endl;

    // Start dialing the new channel
    dial_channel(server_url, new_channel_id, user, password);
    std::cout << "Dialing new channel " << new_channel_id << std::endl;

    return 0;
}
