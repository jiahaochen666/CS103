 ## Implement a simple hashmap with C++
 
<p>The goal of this assignment is to implement a map implemented as a hash table with linked list hash chaining, restricting ourselves mostly to features pre C++11. You will then use this hash table as a map from strings to integers to calculate the word frequency of every word of a text read from standard input and write these frequencies to standard output. The design of the classes you will write is STL-like, meaning that we mimic the idiomatic behavior of the containers of the standard template library. However, you don’t need to implement your solution as a template and only a subset of functions is required to simplify this project.</p>
<p>If you need a refresher on how such a hash table works, you can consult the Wikipedia article about <a href="https://en.wikipedia.org/wiki/Hash_table#Separate_chaining_with_linked_lists" class="external" target="_blank" rel="noreferrer noopener"><span>hash tables</span><span aria-hidden="true" class="ui-icon ui-icon-extlink ui-icon-inline" title="Links to an external site."></span><span class="screenreader-only">&nbsp;(Links to an external site.)</span></a>. In short, a hash table with linked list hash chaining contains an array of <code>n</code> buckets, where each bucket is a linked list of key-value-pairs. A hash function <code>h(k)</code> determines for any given key, in which bucket this entry belongs to. Hence, a bucket <code>b</code> contains all key-value-pairs for which <code>h(k)=b</code>.</p>
<h2 id="guidance">Guidance</h2>
<p>The provided starter code contains the following files:</p>
<ul>
<li><code>main.cpp</code>: the entry point of your program. You will implement the frequency counting there.</li>
<li><code>HashMap.cpp</code> and <code>HashMap.hpp</code>: the header and implementation file for the hash map class.</li>
<li><code>LinkedList.cpp</code> and <code>LinkedList.hpp</code>: the header and implementation for the linked list.</li>
</ul>
<p>Examine the header (<code>.hpp</code>) files to get an idea over the classes you will implement. The hash map uses <code>std::string</code> as key and <code>std::int32_t</code> as value, so we can use it to count the occurrence of each word efficiently in the word frequency program. Because the word frequency depends on the hash map, and the hash map depends on the linked list, you will first implement the linked list, then the hash map and finally the word frequency.</p>
<h3 id="implementing-the-linked-list">1. Implementing the linked list</h3>
<ol type="1">
<li>Define the <code>LinkedList::Entry</code> class. This contains a pointer to the next entry and a value of type <code>LinkedList::Value</code>. This class is already declared in the header file and it is sufficient to define it in the cpp file.</li>
<li>Implement a constructor which initializes an empty list and a destructor which deletes all entries in the list.</li>
<li>Implement <code>push_front</code> which adds a new element to the start of the list and updates the head pointer.</li>
<li>Implement <code>begin</code> and <code>end</code> which return an iterator the head of the list and the <code>nullptr</code> respectively.</li>
<li>Initialize the field that contains a pointer to the current entry in the constructor of the iterator.</li>
<li>Implement the comparison, increment and dereferencing operators of the iterator.</li>
</ol>
<h3 id="implementing-the-hash-map">2. Implementing the hash map</h3>
<ol type="1">
<li>
<p>Initialize these fields in the constructor. Because we want to be able to resize the map dynamically, you need to allocate an array of lists dynamically. Choose a reasonable number of buckets to start with (something like 7). You should implement this in the private function <code>initialize_storage</code>, as you can reuse this function while resizing the hash map.</p>
<p>However, allocate the bucket array one element larger than the actual bucket number. So when bucket count is seven, allocate an array of 8 lists. Add also a dummy entry to this extra list. This dummy entry can just have default values for the key-value-pair. This will simplify iterating through the hash map as we will see later.</p>
</li>
<li>
<p>Implement the destructor, which <code>delete[]</code>s the array of buckets.</p>
</li>
<li>
<p>Implement <code>begin</code> and <code>end</code>. The begin iterator has a pointer to the first bucket and the begin iterator of this bucket. The end iterator has a pointer to the extra bucket that was allocated and its begin (not end!) iterator.</p>
</li>
<li>
<p>Implement <code>get_bucket</code>: to do so, you will need a hash function. A good and fast hash function is <a href="https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function#FNV-1_hash" class="external" target="_blank" rel="noreferrer noopener"><span>FNV-1</span><span aria-hidden="true" class="ui-icon ui-icon-extlink ui-icon-inline" title="Links to an external site."></span><span class="screenreader-only">&nbsp;(Links to an external site.)</span></a>. If you choose to implement the 64-bit version, the offset basis is <code>14695981039346656037ull</code> and the prime is <code>1099511628211</code>. Use iterators to iterate through all characters (= bytes) of the key. To get index of the bucket, calculate the hash modulo the bucket count and return a reference to that bucket.</p>
</li>
<li>
<p>Implement <code>find</code>: get the bucket with <code>get_bucket</code> and check whether it contains any entry with the same key. If yes, return an iterator to this bucket and the iterator to this entry. Otherwise return <code>end()</code>.</p>
</li>
<li>
<p>Implement <code>insert</code>: this function first looks up, whether the key-value-pair already exists. If it exists it returns the iterator to the existing key-value-pair and <code>false</code>. If it was inserted, it returns the iterator to the new key-value-pair and <code>true</code>. To insert, retrieve the hash bucket with <code>get_bucket</code> and <code>push_front</code> the key-value-pair to it. Don’t forget to update the size of the hash map.</p>
<p>To maintain a good performance, we want to keep the load factor of the hash table in a certain range. If this value goes out of this range, we need to increase the number of buckets. A reasonable range would be to keep the load factor between 1 and 2 (this is probably not optimal, but easy to implement). This means, if there are more than twice as many elements in the hash table than there are buckets, add increase buckets such that the load factor decreases to 1. However, when we add more buckets, we need to rehash all elements.</p>
<p>To implement this, check during insertion, whether there are more than twice as many elements in the map than there are buckets. If yes, we want to reallocate the array containing all buckets with the size equal to the number of key-value-pairs in the hash map. One way to implement this is to copy the pointer to the old bucket array and its size in a local variable. Then you call <code>initialize_storage</code> with the new size, which will create a new array and reset the size (number of elements in the map) to 0. Then you iterate through all the entries of entries of the old bucket array and copy them into the new storage by calling <code>insert</code> recursively. Finally, remember to <code>delete[]</code> the old array.</p>
</li>
<li>
<p>Implement the <code>operator[]</code>, which calls <code>insert</code> with the key and 0 as value and returns a reference to the value from the iterator returned from <code>insert</code>. This works, because <code>insert</code> will only insert the element if it was not present, otherwise it will just return an iterator to the existing one and not modify the map.</p>
</li>
<li>
<p>Implement the constructor for the iterator: in the function <code>begin</code> we passed a pointer to the first bucket and the iterator when calling <code>begin</code> on that bucket. However, this bucket might be empty, and we want the iterator always point to a valid element (or to the end). Hence we need to advance the iterator in the constructor until an element is reached. You can do this by incrementing the bucket pointer until you find a bucket that is not empty (compare <code>bucket-&gt;begin()</code> and <code>bucket-&gt;end()</code>). If the hash map is empty, there will be always the dummy entry in the extra bucket, which prevents us from reading out-of-bounds memory.</p>
</li>
<li>
<p>Implement <code>operator++</code> on the iterator like you implemented the constructor, but with an increment.</p>
</li>
<li>
<p>Implement the remaining operators on the iterator.</p>
</li>
</ol>
<h3 id="implementing-the-word-frequency">2. Implementing the word frequency</h3>
<ol type="1">
<li>
<p>Read one word at a time from <code>std::cin</code> and increment its count in the hash map (you can use the <code>[]</code> operator).</p>
</li>
<li>
<p>Iterate through the entire hash map to print all key-value-pairs like this (note the double spaces before and after the hyphen):</p>
<pre><code>word1  -  12
word2  -  16</code></pre>
</li>
</ol>
