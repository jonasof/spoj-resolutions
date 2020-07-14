use std::io;
use std::str::FromStr;

// Problem https://www.spoj.com/problems/FCTRL/

fn main() {
    let amount_of_tests = read_line::<i64>().unwrap();

    for _ in 0..amount_of_tests {
        let number = read_line::<i64>().unwrap();

        let response = get_amount_of_zeroes(number);

        println!("{}", response.to_string().as_str());
    }
}

// Abstract calls to read a line from stdin.
fn read_line <T: FromStr>() -> Result<T, T::Err> {
    let mut value = String::new();

    io::stdin().read_line(&mut value);

    return value.trim_end().parse::<T>();
}

// Based on https://nerdparadise.com/math/factorialzeros explanation
fn get_amount_of_zeroes(number: i64) -> i64 {
    let mut amount_of_zeroes = 0;
    let mut five_factor_iterator = 1;

    loop {
        let zeroes_to_be_added = number / (5 as i64).pow(five_factor_iterator);

        if zeroes_to_be_added == 0 {
            break;
        }

        amount_of_zeroes += zeroes_to_be_added;

        five_factor_iterator += 1;
    }

    return amount_of_zeroes;
}