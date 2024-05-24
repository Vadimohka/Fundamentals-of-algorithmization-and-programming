

node* before_el, after_el;
node* new_el;


before_el->next = new_el;
new_el->prev = before_el;

new_el->next = after_el;
after_el->prev = new_el;