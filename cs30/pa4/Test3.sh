#!bin/bash
bash TestFinal1.sh >& MYSOL
bash TestFinal2.sh >& REFSOL
diff MYSOL REFSOL 
