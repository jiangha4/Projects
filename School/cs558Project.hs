import Data.Char

-- Implemention 1 Linked list

{- 
	type dict<V>
	operations:
		empty : unit -> dict<V>
		lookup : dict<V> -> string -> (V + NotFound)
		insert : dict<V> -> string -> V -> unit
		fold : dict<V> -> <T> -> (<T> -> string -> V -> <T>) -> <T>
-}

data MyMaybe a = MyNothing | MyJust a deriving (Show, Eq, Ord)
data LinkedListDict a b = Entry ((a, b), LinkedListDict a b) | MyNil deriving (Show, Eq)

myList :: LinkedListDict Int Bool
myList = Entry ((1, True) ,Entry ((0, False), MyNil))

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

myFold :: LinkedListDict a b -> b -> (b -> b -> b) -> b
myFold curDict starter func = 
	case curDict of
		Entry ((curKey, curValue), nextEntry) -> myFold nextEntry (func starter curValue) func
		MyNil -> starter

-- Implementation 2 Hash Table
data HashTableEntry a b = Slot (a, b) | Empty deriving (Show, Eq)
data HashTableDict a b = Table [HashTableEntry a b] deriving (Show, Eq)

myHashTableLen :: Int
myHashTableLen = 1000

--myHashTable :: HashTableDict Int Bool
--myHashTable = Table [[(0, True)], [(1, False)], [(2, True)]]

myHashingFunc :: [Char] -> Int 
myHashingFunc key = mod (foldl (\acc x -> (ord x) + acc) 0 key) myHashTableLen

myEmptyHash :: HashTableDict a b
myEmptyHash = Table (take myHashTableLen (repeat Empty))

myLookupHash :: Eq a => Eq b => HashTableDict a b -> [Char] -> Int
myLookupHash table curKey = (myHashingFunc curKey)
