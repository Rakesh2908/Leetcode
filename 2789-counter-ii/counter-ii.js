/**
 * @param {integer} init
 * @return {Object} counter object with methods
 */
var createCounter = function(init) {
    var x = init;

    return {
        increment: () => {
            return ++x;
        },

        decrement: () => {
            return --x;
        },

        reset: () => {
            x = init;
            return x;
        }
    };
};


