mkdir $1
cd $1 
mkdir Dir1
chmod 770 Dir1
cd Dir1
touch File1
chmod 400 File1
mkdir Dir3
cd Dir3
mkdir Dir4
chmod 750 Dir4
cd Dir4
touch File4
chmod 666 File4
touch File3
chmod 200 File3
cd ..
cd ..
chmod 000 Dir3
cd ..
mkdir Dir2
chmod 775 Dir2
cd Dir2
touch File2
chmod 640 File2
