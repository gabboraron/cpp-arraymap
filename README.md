# template arrays_map
kulcs-ertek párok
array_map<key,T>
azonos tömbindexen hogy milyen kulcs milyen értékkel
>            két tömb, egyikben kulcsok  7     3     2    9
>                               ertekek "xy" "abc" "def"
ha nem egyezik meg a két tömb elemszáma akkro a map a rövidekbbikhez igazodik, így ebben a plben a 9esnek nincs hozzá tartozó elem 
at(key) return hozzátartozó érték első tömb szerintei legelső előfordulást adja vissza
map indexelése operator () on keresztül megváltoztatva akkor a tényleges tömb elemei is megváltoznak
copy tagfüggvény(m) a copy mapjébe kerüljön be az ami az arraysben van
arrays map std mappé konvertálódhasson
