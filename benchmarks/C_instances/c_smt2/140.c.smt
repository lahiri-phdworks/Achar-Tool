(set-logic LIA)

( declare-const i Int )
( declare-const i! Int )
( declare-const n Int )
( declare-const n! Int )
( declare-const sum Int )
( declare-const sum! Int )

( declare-const i_0 Int )
( declare-const i_1 Int )
( declare-const i_2 Int )
( declare-const n_0 Int )
( declare-const sum_0 Int )
( declare-const sum_1 Int )
( declare-const sum_2 Int )

( define-fun inv-f( ( i Int )( n Int )( sum Int ) ) Bool
SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
)

( define-fun pre-f ( ( i Int )( n Int )( sum Int )( i_0 Int )( i_1 Int )( i_2 Int )( n_0 Int )( sum_0 Int )( sum_1 Int )( sum_2 Int ) ) Bool
	( and
		( = i i_0 )
		( = n n_0 )
		( = sum sum_0 )
		( >= n_0 0 )
		( = i_0 0 )
		( = sum_0 0 )
	)
)

( define-fun trans-f ( ( i Int )( n Int )( sum Int )( i! Int )( n! Int )( sum! Int )( i_0 Int )( i_1 Int )( i_2 Int )( n_0 Int )( sum_0 Int )( sum_1 Int )( sum_2 Int ) ) Bool
	( or
		( and
			( = i_1 i )
			( = sum_1 sum )
			( = i_1 i! )
			( = sum_1 sum! )
			( = n n_0 )
			( = n! n_0 )
			( = sum sum! )
		)
		( and
			( = i_1 i )
			( = sum_1 sum )
			( < i_1 n_0 )
			( = i_2 ( + i_1 1 ) )
			( = sum_2 ( + sum_1 ( * i_2 i_2 ) ) )
			( = i_2 i! )
			( = sum_2 sum! )
			(= n n_0 )
			(= n! n_0 )
		)
	)
)

( define-fun post-f ( ( i Int )( n Int )( sum Int )( i_0 Int )( i_1 Int )( i_2 Int )( n_0 Int )( sum_0 Int )( sum_1 Int )( sum_2 Int ) ) Bool
	( or
		( not
			( and
				( = i i_1)
				( = n n_0)
				( = sum sum_1)
			)
		)
		( not
			( and
				( not ( < i_1 n_0 ) )
				( not ( = sum_1 ( / ( * ( * n_0 ( + n_0 1 ) ) ( + ( * 2 n_0 ) 1 ) ) 6 ) ) )
			)
		)
	)
)
SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
( assert ( not
	( =>
		( pre-f i n sum i_0 i_1 i_2 n_0 sum_0 sum_1 sum_2  )
		( inv-f i n sum )
	)
))

SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
( assert ( not
	( =>
		( and
			( inv-f i n sum )
			( trans-f i n sum i! n! sum! i_0 i_1 i_2 n_0 sum_0 sum_1 sum_2 )
		)
		( inv-f i! n! sum! )
	)
))

SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
( assert ( not
	( =>
		( inv-f i n sum  )
		( post-f i n sum i_0 i_1 i_2 n_0 sum_0 sum_1 sum_2 )
	)
))

