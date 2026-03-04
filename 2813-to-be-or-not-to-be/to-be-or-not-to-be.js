var expect = function(val) {
    return {
        val: val,
        toBe: function(expected) {
            if (this.val === expected) return true;
            throw new Error("Not Equal");
        },
        notToBe: function(expected) {
            if (this.val !== expected) return true;
            throw new Error("Equal");
        }
    };
};