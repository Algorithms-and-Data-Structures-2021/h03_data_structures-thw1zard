#include "linked_queue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

    void LinkedQueue::Enqueue(Element e) {
        SinglyNode *new_node = new SinglyNode(e, nullptr);
        if (size_ == 0) {
            front_ = new_node;
            back_ = front_;

        }
        if (size_ > 0) {
            back_->next = new_node;
            back_ = new_node;
        }
        size_++;

    }


    void LinkedQueue::Dequeue() {
        if (size_ == 0) {
            throw std::logic_error("could not dequeue from empty queue");
        }
        if (size_ == 1) {
            delete front_;
            front_ = nullptr;
            back_ = front_;
            size_--;
        }
        if(size_ > 1){
            auto* delete_node = front_;
            front_ = front_ -> next;
            delete delete_node;
            size_--;
        }



    }

    void LinkedQueue::Clear() {
        SinglyNode* curr_node = front_;
        while(curr_node != nullptr){
            SinglyNode* nextNode = curr_node->next;
            delete curr_node;
            front_ = nextNode;
            curr_node = front_;
            size_ -= 1;
        }
        back_ = nullptr;
        // TODO: напишите здесь свой код ...
    }

// === РЕАЛИЗОВАНО ===

    LinkedQueue::~LinkedQueue() {
        Clear();
    }

    std::optional<Element> LinkedQueue::front() const {
        return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
    }

    std::optional<Element> LinkedQueue::back() const {
        return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
    }

    bool LinkedQueue::IsEmpty() const {
        return size_ == 0;
    }

    int LinkedQueue::size() const {
        return size_;
    }

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

    std::ostream &operator<<(std::ostream &os, const LinkedQueue &queue) {
        os << "size: " << queue.size_ << '\n';
        for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->next) {
            if (current_node == queue.front_) os << "[FRONT] ";
            if (current_node == queue.back_) os << "[BACK] ";
            os << enum2str(current_node->data) << '\n';
        }
        return os;
    }

}  // namespace itis