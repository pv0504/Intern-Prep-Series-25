# `OSI` + `TCP/IP` Models for Network Communication

## Table of Contents

- [Introduction](#introduction)
- [Explanation of Basic Concepts](#explanation-of-basic-concepts)
- [Hands-On Task](#hands-on-task)
- [Common Pitfalls](#common-pitfalls)
- [Resources](#resources)

---

## Introduction

Modern computer networks follow layered models to standardize communication across devices. Two major models are:

- The **OSI Model** — a 7-layer theoretical framework
- The **TCP/IP Model** — a 4-layer practical implementation used on the Internet

Understanding these models helps developers and engineers diagnose networking issues, build applications, and implement protocols.

Key concepts include:
- **Abstraction of responsibilities** across layers
- **Encapsulation** of data as it moves through the layers
- **Protocol layering** and interoperability (e.g., HTTP over TCP/IP)

---

## Explanation of Basic Concepts

### Layered Network Architecture

| OSI Layer        | Function                        | TCP/IP Equivalent |
|------------------|----------------------------------|--------------------|
| 7: Application   | End-user applications            | Application        |
| 6: Presentation  | Data format/encoding/encryption  | Application        |
| 5: Session       | Session management               | Application        |
| 4: Transport     | Reliable/unreliable delivery     | Transport          |
| 3: Network       | Logical addressing and routing   | Internet           |
| 2: Data Link     | Frame delivery on local network  | Network Access     |
| 1: Physical      | Physical transmission (bits)     | Network Access     |

---

### OSI Model (7 Layers)

1. **Physical** – Bits over cables, wireless, etc.
2. **Data Link** – Frames, MAC addressing (e.g., Ethernet)
3. **Network** – Packets, IP addressing, routing
4. **Transport** – TCP/UDP, ports, reliability
5. **Session** – Managing sessions (rarely separated)
6. **Presentation** – Encoding (e.g., ASCII, JPEG), encryption
7. **Application** – Protocols like HTTP, FTP, SMTP

---

### TCP/IP Model (4 Layers)

1. **Network Access** – Combines OSI Physical + Data Link
2. **Internet** – Routing and addressing (IP)
3. **Transport** – TCP (reliable), UDP (fast)
4. **Application** – Protocols used by apps (HTTP, DNS, etc.)

---

### Encapsulation Example

When sending an HTTP request:

```
Application Layer: HTTP data
↓
Transport Layer: TCP adds port/address
↓
Internet Layer: IP adds source/destination IP
↓
Network Access Layer: Ethernet adds MAC + physical transmission
```

Each layer **wraps** the data from the above layer.

---

## Hands-On Task

### Conceptual

1. **Why is layering useful in network models?**
2. **What are the key differences between the OSI and TCP/IP models?**
3. **Which protocols operate at each layer? (e.g., DNS, IP, TCP)**

### Practical

1. **Packet Analysis with Wireshark**:
   - Capture a simple HTTP request.
   - Identify the layers: Ethernet → IP → TCP → HTTP.

2. **Port Identification**:
   - What does TCP port 80 or 443 indicate?
   - How can you verify open ports using `netstat` or `ss`?

3. **Command Line Tools**:
   - Use `ping` and `traceroute` to explore the Internet layer.
   - Use `telnet` or `curl` to interact with the Application layer.

### Numerical

1. **Transport Header Size**:
   - TCP adds a 20-byte header. What is the total overhead for an HTTP payload of 100 bytes?

2. **IP Fragmentation**:
   - If MTU is 1500 bytes and IP header is 20 bytes, what is the max payload size?

---

## Common Pitfalls

- **Confusing OSI with TCP/IP** — OSI is conceptual, TCP/IP is implemented.
- **Ignoring layers in debugging** — E.g., blaming HTTP when the TCP connection failed.
- **Misusing terms** — TCP is *not* the same as IP, nor is it an Application Layer protocol.
- **Neglecting security** — SSL/TLS is part of the Presentation layer (or Application in TCP/IP).
- **Assuming all protocols use TCP** — Some use UDP (e.g., DNS, VoIP).

---

## Resources

### Video

- [OSI Model Explained (Practical Networking)](https://www.youtube.com/watch?v=vv4y_uOneC0)
- [TCP/IP Stack Overview (PowerCert)](https://www.youtube.com/watch?v=G9S0l4qj4Gg)
- [Wireshark Tutorial for Beginners](https://www.youtube.com/watch?v=TkCSr30UojM)

### Tools

- `Wireshark` – Packet sniffer for layer analysis
- `netcat`, `curl`, `ping`, `traceroute` – CLI tools for testing each layer
- `nmap` – Port scanning tool
