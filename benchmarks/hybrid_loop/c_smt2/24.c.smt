(set-logic LIA)

( declare-const i Int )
( declare-const i! Int )
( declare-const j Int )
( declare-const j! Int )

( declare-const i_0 Int )
( declare-const i_1 Int )
( declare-const j_0 Int )
( declare-const j_1 Int )
( declare-const j_2 Int )
( declare-const j_3 Int )

( define-fun inv-f( ( i Int )( j Int ) ) Bool
SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
)

( define-fun pre-f ( ( i Int )( j Int )( i_0 Int )( i_1 Int )( j_0 Int )( j_1 Int )( j_2 Int )( j_3 Int ) ) Bool
	( and
		( = i i_1 )
		( = j j_1 )
		( = i_1 1 )
		( = j_1 10 )
	)
)

( define-fun trans-f ( ( i Int )( j Int )( i! Int )( j! Int )( i_0 Int )( i_1 Int )( j_0 Int )( j_1 Int )( j_2 Int )( j_3 Int ) ) Bool
	( or
		( and
			( = j_2 j )
			( = j_2 j! )
			( = i i_1 )
			( = i! i_1 )
		)
		( and
			( = j_2 j )
			( >= j_2 i_1 )
			( = 1 2 )
			( = j_3 ( - j_2 1 ) )
			( = j_3 j! )
			(= i i_1 )
			(= i! i_1 )
		)
	)
)

( define-fun post-f ( ( i Int )( j Int )( i_0 Int )( i_1 Int )( j_0 Int )( j_1 Int )( j_2 Int )( j_3 Int ) ) Bool
	( or
		( not
			( and
				( = i i_1)
				( = j j_2)
			)
		)
		( not
			( and
				( not ( >= j_2 i_1 ) )
				( not ( = j_2 6 ) )
			)
		)
	)
)
SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
( assert ( not
	( =>
		( pre-f i j i_0 i_1 j_0 j_1 j_2 j_3  )
		( inv-f i j )
	)
))

SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
( assert ( not
	( =>
		( and
			( inv-f i j )
			( trans-f i j i! j! i_0 i_1 j_0 j_1 j_2 j_3 )
		)
		( inv-f i! j! )
	)
))

SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
( assert ( not
	( =>
		( inv-f i j  )
		( post-f i j i_0 i_1 j_0 j_1 j_2 j_3 )
	)
))

