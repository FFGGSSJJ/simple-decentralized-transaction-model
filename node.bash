#!bin/bash

# pass kill signal to the process
_term() { 
    echo "Caught SIGTERM signal!" 
    kill -TERM "$child" 2>/dev/null
}

trap _term SIGTERM

make node
python3 -u gentx.py 0.5 | ./node $NODE_ID $NODE_PORT $NODE_CONFIG_PATH &

child=$! 
wait "$child"