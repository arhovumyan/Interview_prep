/* you are given bunch of raw bytes that represent a packet.
    raw byte is an 8-bit piece of data before you interpret it
you need to read the header fiel fields(length, type, sequence number, checksum)
use the length to figure out where the payload is
make sure the packet is not malformed(like claiming a payload longer than the buffer)
recalculate the cehcksum and compare it to the checksum int he header
    checksum is a small calculated value used to check if data was corrupted
if everything valid, return the decoded packet, otherwise reject
*/

#include <iostream>
#include <vector>
#include <cstdint>

struct Packet {
    uint16_t length;
    uint8_t type;
    uint16_t sequence;
    uint16_t checksum;
    std::vector<uint8_t> payload;
};

// buf is the raw bytes coming in
// packet is where we store the decoded result
bool decodePacket(const std::vector<uint8_t>& buf, 
    Packet& packet) {
        const int HEADER_SIZE = 7;

        if (buf.size() < HEADER_SIZE) return false;
        
        // since our vector is made out of 8bit uints, 
        // we want to combine 2 for variables that require 16
        packet.length = (buf[0] << 8) | buf[1];
        packet.type = (buf[2] << 8);
        packet.sequence = (buf[3] << 8) | buf[4];
        packet.checksum = (buf[5] << 8) | buf[6];

        if (buf.size() < HEADER_SIZE + packet.length) return false;

        packet.payload.assign( // take these bytes from buf and put them intput paclet.payload
            buf.begin() + HEADER_SIZE, // start after the 7-byte header
            buf.begin() + HEADER_SIZE + packet.length // end here
        );

        uint16_t sum = 0;
        for (uint8_t b : packet.payload){
            sum += b;
        }

        return sum == packet.checksum;
    }


int main() {

    // Raw packet bytes
    std::vector<uint8_t> rawBytes = {
        0x00, 0x03, // length = 3
        0x01,       // type = 1
        0x00, 0x02, // sequence = 2
        0x00, 0x3C, // checksum = 60

        // payload
        10, 20, 30
    };

    Packet packet;

    if (decodePacket(rawBytes, packet)) {

        std::cout << "Valid packet\n";

        std::cout << "Length: " << packet.length << "\n";
        std::cout << "Type: " << static_cast<int>(packet.type) << "\n";
        std::cout << "Sequence: " << packet.sequence << "\n";
        std::cout << "Checksum: " << packet.checksum << "\n";

        std::cout << "Payload: ";

        for (uint8_t b : packet.payload) {
            std::cout << static_cast<int>(b) << " ";
        }

        std::cout << "\n";

    } else {

        std::cout << "Invalid packet\n";
    }

    return 0;
}