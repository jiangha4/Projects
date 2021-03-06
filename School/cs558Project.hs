import Data.Char

-- Implemention 1 Linked list
data MyMaybe a = MyNothing | MyJust a deriving (Show, Eq, Ord)
data LinkedListDict a b = Entry ((a, b), LinkedListDict a b) | MyNil deriving (Show, Eq)

myEmpty :: LinkedListDict a b
myEmpty = MyNil

myInsert :: Eq a => Eq b => LinkedListDict a  b -> a -> b -> LinkedListDict a b
myInsert curDict newKey newValue = 
	case myLookup curDict newKey of
		MyJust a -> myInsertHelper curDict newKey newValue
		MyNothing -> Entry ((newKey, newValue), curDict) 

myInsertHelper :: Eq a => Eq b => LinkedListDict a b -> a -> b -> LinkedListDict a b
myInsertHelper curDict newKey newValue =
	case curDict of
		Entry ((curKey, curValue), nextEntry) -> 
			if curKey == newKey then Entry ((curKey, newValue), nextEntry) 
								else Entry ((curKey, curValue), myInsertHelper nextEntry newKey newValue)

myLookup :: Eq a => Eq b => LinkedListDict a b -> a -> MyMaybe b
myLookup curDict key = 
	case curDict of
		Entry ((curKey, curValue), nextEntry) -> 
			if curKey == key then MyJust curValue else myLookup nextEntry key
		MyNil -> MyNothing

--myFold :: LinkedListDict a b -> b -> (b -> b -> b) -> b
myFold curDict starter func = 
	case curDict of
		Entry ((curKey, curValue), nextEntry) -> myFold nextEntry (func curValue starter) func
		MyNil -> starter

-- Implementation 2 Hash Table
data HashTableEntry a b = Slot (a, b) | Empty deriving (Show, Eq)

myHashTableLen :: Int
myHashTableLen = 1000

myHashingFunc :: [Char] -> Int 
myHashingFunc key = mod (foldl (\acc x -> (ord x) + acc) 0 key) myHashTableLen

myEmptyHash :: [HashTableEntry a b]
myEmptyHash = take myHashTableLen (repeat Empty) 

myLookupHash :: [HashTableEntry a b] -> [Char] -> MyMaybe b
myLookupHash table curKey = 
	case table!!(myHashingFunc curKey) of
		Slot (key, value) -> MyJust value
		Empty -> MyNothing

linearProbe :: [HashTableEntry a b] -> Int -> Int
linearProbe table index =
	case table!!index of
		Slot (key, value) -> linearProbe table (index + 1)
		Empty -> index

myInsertHash :: Eq b => [HashTableEntry [Char] b]  -> [Char] -> b -> [HashTableEntry [Char] b]
myInsertHash table newKey newValue = 
	case (myLookupHash table newKey) of
		MyJust value -> 
			if newValue == value then myInsertHashHelper table (myHashingFunc newKey) newKey newValue
								 else myInsertHashHelper table (linearProbe table ((myHashingFunc newKey) + 1)) newKey newValue
		MyNothing -> myInsertHashHelper table (myHashingFunc newKey) newKey newValue

myInsertHashHelper :: Eq b => [HashTableEntry [Char] b] -> Int -> [Char] -> b -> [HashTableEntry [Char] b]
myInsertHashHelper table index newKey newValue =
	let (previous, slot:next) = splitAt index table in previous ++ [Slot (newKey, newValue)] ++ next

-- myHashFold :: [HashTableEntry [Char] b] -> b -> (b -> a -> b) -> a
myHashFold table starter func =
	case table of
		(Slot (key, value) : nextSlot) -> myHashFold nextSlot (func value starter) func
		(Empty : nextSlot) -> myHashFold nextSlot starter func
		_ -> starter

-- Client

-- Creating the empty list for a linked list dictionary
testDictLL :: LinkedListDict [Char] (Integer, Bool)
testDictLL = myEmpty

-- Creating the empty table for a hash table dictionary
testDictHash :: [HashTableEntry [Char] (Integer, Bool)]
testDictHash = myEmptyHash


-- Generation of the (Int, Bool) pairs and the [Char] key

-- Key Generation
-- [Char] key is generated by mapping a list of [1..499] to a repeat of a string "a". 
-- The take functionality allows us to take a subset of the infinite repeating string
-- The concat then concatenates the list of 'a' into a string
genList n list = map (\x -> concat (take (n*x) (repeat "a"))) list
-- Running the genList function to return to us a list of 2i copies of 'a'
testListKeys = genList 2 [1..499]

-- Value Pair Generation
-- Key of the pair is 1 <= i < 500
testListPairKey = [1..499]
-- Map the list of the key to create values of true/false depending on if the key is even/odd
makeTestListPairValue list = map (\x -> if (mod x 2) == 0 then True else False) list
testListPairValue = makeTestListPairValue testListPairKey
-- Zipping key and value lists together to create value pair 
testListPair = zip testListPairKey testListPairValue

-- Zipping key and pair together to create test data
insertList = zip testListKeys testListPair

-- Insertation into linked list
linkedListInserter dict key value = if ((tail key) == [])
			then myInsert dict (head key) (head value)
			else linkedListInserter (myInsert dict (head key) (head value)) (tail key) (tail value) 

dictLL = linkedListInserter testDictLL testListKeys testListPair

-- Insertation into hash table
hashTableInserter dict key value = if ((tail key) == [])
			then myInsertHash dict (head key) (head value)
			else hashTableInserter (myInsertHash dict (head key) (head value)) (tail key) (tail value) 

dictHT = hashTableInserter testDictHash testListKeys testListPair

-- Generation of lookup list
lookupList = genList 3 [1..332]

-- Lookup on linked list dict
lookupLL = map (\key -> myLookup dictLL key) lookupList 
foundLL = filter (\entry -> if entry == MyNothing then False else True) lookupLL

-- Lookup on hash table dict
lookupHash = map (\key -> myLookupHash dictHT key) lookupList
foundHT = filter (\entry -> if entry == MyNothing then False else True) lookupHash

-- Function that determines if value in the pair is true
trueOrFalse entry acc = 
	case entry of
		(key, value) -> if value then acc + 1 else acc

-- Number of copies Linked List		
numOfCopiesLL dict = myFold dict 0 trueOrFalse
numCopiesLL = numOfCopiesLL dictLL

-- Number of copies Hash Table
numofCopiesHT dict = myHashFold dict 0 trueOrFalse
numCopiesHT = numofCopiesHT dictHT

main = do 
	putStrLn "----------------------- CS 558 Project ------------------------"
	putStrLn "\n"
	putStr "For additional information on implementation of the client, or either implementations "
	putStrLn "of the dictionary the source code has comments."
	putStrLn "----------------------- Part 1 ------------------------"
	putStrLn "\n"
	putStrLn "Creating Empty Dictionaries"
	putStrLn "Creating 1000 empty entries for Hash table dictionary"
	putStrLn "\n"
	putStrLn "Creating Empty Linked List Dictionary"	
	putStrLn "To view empty dictionaries, type into ghci testDictLL for linked list and testDictHT for hash table" 
	putStrLn "\n"
	putStrLn "---------------------------------------------------------"
	putStrLn "\n"
	putStrLn "----------------------- Part 2 -------------------------"
	putStrLn "\n"
	putStrLn "Values being inserted into dictionaries are of type ([Char], (Int, Bool))"
	putStrLn "To view dictionaries after insertation, type into ghci dictLL for linked list and dictHT for hash table" 
	putStrLn "\n"
	putStrLn "---------------------------------------------------------"
	putStrLn "\n"
	putStrLn "----------------------- Part 3 -------------------------"
	putStrLn "\n"
	putStrLn "Finding all values whose key is 3i when 1 <= i < 333"	
	putStrLn "Typing foundLL will return a list of all values whose keys are 3i using the Linked List implementation"
	putStrLn "Typing foundHT will return a list of all values whose keys are 3i using the hash table implementation"
	putStrLn "\n"
	putStrLn "---------------------------------------------------------"
	putStrLn "\n"
	putStrLn "----------------------- Part 4 -------------------------"
	putStrLn "\n"
	putStrLn "Using myFold to compute the number of entries with true as a value "
	putStrLn "Typing numCopiesLL will return the number using linked list implementation"
	putStrLn "Typing numCopesHT will return the number using hash table implementation"
	putStrLn "\n"
	putStrLn "---------------------------------------------------------"
