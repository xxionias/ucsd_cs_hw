#!bin/bash
bash TestEval.sh &> MYSOL
cd ~/../public
bash ~/pa4/TestEval.sh &> ~/pa4/REFSOL
cd ~/pa4
diff MYSOL REFSOL
