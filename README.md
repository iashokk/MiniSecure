# MiniSecure (POC)

Toy client–server handshake (NOT real crypto):

1) ClientHello (client_nonce, version)
2) ServerHello (server_nonce, accept)
3) Derive key: K = H(psk|c|s)
4) Finished: toy HMAC over transcript

Contains intentional bugs for RCA demonstrations.
