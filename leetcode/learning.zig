const std = @import("std");

pub fn main() void {
    const user = User{
        .power = "master",
        .name = "thevoid3301",
    };

    std.debug.print("{s}'s power is {s}\n", .{ user.name, user.power });
}

pub const User = struct {
    power: []const u8,
    name: []const u8,
};
