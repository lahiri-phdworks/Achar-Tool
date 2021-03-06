(set-logic LIA)

( declare-const c Int )
( declare-const c! Int )
( declare-const tmp Int )
( declare-const tmp! Int )

( declare-const c_0 Int )
( declare-const c_1 Int )
( declare-const c_2 Int )
( declare-const c_3 Int )
( declare-const c_4 Int )

( define-fun inv-f( ( c Int )( tmp Int ) ) Bool
SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
)

( define-fun pre-f ( ( c Int )( tmp Int )( c_0 Int )( c_1 Int )( c_2 Int )( c_3 Int )( c_4 Int ) ) Bool
	( and
		( = 1 2 )
	)
)

( define-fun trans-f ( ( c Int )( tmp Int )( c! Int )( tmp! Int )( c_0 Int )( c_1 Int )( c_2 Int )( c_3 Int )( c_4 Int ) ) Bool
	( or
		( and
			( = c_1 c )
			( = c_1 c! )
			( = c c! )
			(= tmp tmp! )
		)
		( and
			( = c_1 c )
			( not ( = c_1 4 ) )
			( = c_2 ( + c_1 1 ) )
			( = c_3 c_2 )
			( = c_3 c! )
			(= tmp tmp! )
		)
		( and
			( = c_1 c )
			( not ( not ( = c_1 4 ) ) )
			( = c_3 c_1 )
			( = c_3 c! )
			(= tmp tmp! )
		)
		( and
			( = c_1 c )
			( = c_1 4 )
			( = c_4 1 )
			( = c_3 c_4 )
			( = c_3 c! )
			(= tmp tmp! )
		)
		( and
			( = c_1 c )
			( not ( = c_1 4 ) )
			( = c_3 c_1 )
			( = c_3 c! )
			(= tmp tmp! )
		)
	)
)

( define-fun post-f ( ( c Int )( tmp Int )( c_0 Int )( c_1 Int )( c_2 Int )( c_3 Int )( c_4 Int ) ) Bool
	( or
		( not
			( = c c_1)
		)
		( not
			( and
				( not ( = c_1 4 ) )
				( not ( <= c_1 4 ) )
			)
		)
	)
)
SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
( assert ( not
	( =>
		( pre-f c tmp c_0 c_1 c_2 c_3 c_4  )
		( inv-f c tmp )
	)
))

SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
( assert ( not
	( =>
		( and
			( inv-f c tmp )
			( trans-f c tmp c! tmp! c_0 c_1 c_2 c_3 c_4 )
		)
		( inv-f c! tmp! )
	)
))

SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
( assert ( not
	( =>
		( inv-f c tmp  )
		( post-f c tmp c_0 c_1 c_2 c_3 c_4 )
	)
))

