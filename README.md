# How to use

1. Clone this repository to the root directory of your libft repository.
2. Run the make command inside this repository.


## 1. Clone this repository
```
$ cd /path/to/your/libft/directory
$ git clone https://github.com/usatie/libft-tester-tokyo.git
$ cd libft-tester-tokyo
```

* If you would like to clone this repository to somewhere else, you can.
In that case, please run the make command like this.
```
$ make LIBFT_DIR=/path/to/your/libft/dir
```

## 2. Test Mandatory functions
```
$ make all
```

If you want to test Libft-00 ~ Libft-02, please use below.  (Please change part number `00` to same as your project.)

```
$ make libft-00
```

<img width="1388" alt="Screen Shot 2022-04-18 at 9 34 55" src="https://user-images.githubusercontent.com/7609060/163738262-2070f78d-83e2-4585-83d4-c65edbcdcddb.png">

## 3. Test Bonus functions
```
$ make bonus
```

## 4. Test individual function
```
$ make strlen
$ make atoi
$ make strnstr
```

If you want to test functions when trying to Libft-00 ~ Libft-02, please type with suffix `.re` like below.

```
$ make strlen.re
$ make atoi.re
$ make strnstr.re
```

<img width="1386" alt="Screen Shot 2022-04-18 at 9 35 27" src="https://user-images.githubusercontent.com/7609060/163738259-a04237e5-d66d-4694-b323-8739b194fe12.png">

## 5. Test Norminette & coding rules
```
$ make norm
```

If you want to run norm check for Libft-00 ~ Libft-02, please use below.  (Please change part number `00` to same as your project.)

```
$ make norm00
```

<img width="1369" alt="Screen Shot 2022-04-18 at 15 27 40" src="https://user-images.githubusercontent.com/7609060/163765260-3fad885b-e00a-4b3f-9468-cc998ae5cb24.png">


# Please add more test cases!
Thanks for trying it out!
If you notice anything or want to add some test cases, feel free to send issues/PRs!

## Sample Code for your first contribution
`ASSERT_EQ`functions are very easy to use.
Basically the first argument is the actual value and the second argument is the expected value.
for creating unit tests
```
int	main(void)
{
	ASSERT_EQ_I(ft_atoi("123"), 123);
	ASSERT_EQ_I(ft_atoi("-42"), -42);
	
	ASSERT_EQ_STR(ft_itoa(123), "123");
	ASSERT_EQ_STR(ft_itoa(-42), "-42");
	
	int	len = 10;
	char *actual = ft_calloc(len, sizeof(char));
	char *expected = calloc(len, sizeof(char));
	ASSERT_EQ_MEM(actual, expected, len);
}
```

## Thanks predecessors!
This project is inspired by these projects, and many cases are imported from them too.
Thanks a lot!
- https://github.com/Tripouille/libftTester
- https://github.com/alelievr/libft-unit-test
