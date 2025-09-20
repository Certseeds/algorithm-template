// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2022-2025 nanoseeds
use std::fmt;

pub struct Rectangle {
    pub width: f64,
    pub height: f64,
}

impl Rectangle {
    pub fn get_area(&self) -> f64 {
        self.width * self.height
    }
    pub fn get_perimeter(&self) -> f64 {
        2.0f64 * (self.width + self.height)
    }
    pub fn display(&self) {
        println!("{}", &self);
    }
}

impl fmt::Display for Rectangle {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        return write!(f, r#"    -------------
    Width:      {}
    Height:     {}
    Area:       {:5.3}
    Perimeter:  {:5.3}"#, self.width, self.height, self.get_area(), self.get_perimeter());
    }
}

