(set-logic LIA)

( declare-const lock Int )
( declare-const lock! Int )
( declare-const x Int )
( declare-const x! Int )
( declare-const y Int )
( declare-const y! Int )
( declare-const tmp Int )
( declare-const tmp! Int )

( declare-const lock_0 Int )
( declare-const lock_1 Int )
( declare-const lock_2 Int )
( declare-const lock_3 Int )
( declare-const lock_4 Int )
( declare-const lock_5 Int )
( declare-const x_0 Int )
( declare-const x_1 Int )
( declare-const x_2 Int )
( declare-const x_3 Int )
( declare-const x_4 Int )
( declare-const y_0 Int )
( declare-const y_1 Int )

( define-fun inv-f( ( lock Int )( x Int )( y Int )( tmp Int ) ) Bool
SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
)

( define-fun pre-f ( ( lock Int )( x Int )( y Int )( tmp Int )( lock_0 Int )( lock_1 Int )( lock_2 Int )( lock_3 Int )( lock_4 Int )( lock_5 Int )( x_0 Int )( x_1 Int )( x_2 Int )( x_3 Int )( x_4 Int )( y_0 Int )( y_1 Int ) ) Bool
	( and
		( = lock lock_1 )
		( = x x_0 )
		( = y y_1 )
		( = y_1 ( + x_0 1 ) )
		( = lock_1 0 )
	)
)

( define-fun trans-f ( ( lock Int )( x Int )( y Int )( tmp Int )( lock! Int )( x! Int )( y! Int )( tmp! Int )( lock_0 Int )( lock_1 Int )( lock_2 Int )( lock_3 Int )( lock_4 Int )( lock_5 Int )( x_0 Int )( x_1 Int )( x_2 Int )( x_3 Int )( x_4 Int )( y_0 Int )( y_1 Int ) ) Bool
	( or
		( and
			( = lock_2 lock )
			( = x_1 x )
			( = lock_2 lock! )
			( = x_1 x! )
			( = y y_1 )
			( = y! y_1 )
			( = lock lock! )
			(= tmp tmp! )
		)
		( and
			( = lock_2 lock )
			( = x_1 x )
			( not ( = x_1 y_1 ) )
			( = lock_3 1 )
			( = x_2 y_1 )
			( = lock_4 lock_3 )
			( = x_3 x_2 )
			( = lock_4 lock! )
			( = x_3 x! )
			(= y y_1 )
			(= y! y_1 )
			(= tmp tmp! )
		)
		( and
			( = lock_2 lock )
			( = x_1 x )
			( not ( = x_1 y_1 ) )
			( = lock_5 0 )
			( = x_4 y_1 )
			( = 1 2 )
			( = lock_4 lock_5 )
			( = x_3 x_4 )
			( = lock_4 lock! )
			( = x_3 x! )
			(= y y_1 )
			(= y! y_1 )
			(= tmp tmp! )
		)
	)
)

( define-fun post-f ( ( lock Int )( x Int )( y Int )( tmp Int )( lock_0 Int )( lock_1 Int )( lock_2 Int )( lock_3 Int )( lock_4 Int )( lock_5 Int )( x_0 Int )( x_1 Int )( x_2 Int )( x_3 Int )( x_4 Int )( y_0 Int )( y_1 Int ) ) Bool
	( or
		( not
			( and
				( = lock lock_2)
				( = x x_1)
				( = y y_1)
			)
		)
		( not
			( and
				( not ( not ( = x_1 y_1 ) ) )
				( not ( = lock_2 1 ) )
			)
		)
	)
)
SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
( assert ( not
	( =>
		( pre-f lock x y tmp lock_0 lock_1 lock_2 lock_3 lock_4 lock_5 x_0 x_1 x_2 x_3 x_4 y_0 y_1  )
		( inv-f lock x y tmp )
	)
))

SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
( assert ( not
	( =>
		( and
			( inv-f lock x y tmp )
			( trans-f lock x y tmp lock! x! y! tmp! lock_0 lock_1 lock_2 lock_3 lock_4 lock_5 x_0 x_1 x_2 x_3 x_4 y_0 y_1 )
		)
		( inv-f lock! x! y! tmp! )
	)
))

SPLIT_HERE_asdfghjklzxcvbnmqwertyuiop
( assert ( not
	( =>
		( inv-f lock x y tmp  )
		( post-f lock x y tmp lock_0 lock_1 lock_2 lock_3 lock_4 lock_5 x_0 x_1 x_2 x_3 x_4 y_0 y_1 )
	)
))

