#include "linked_dequeue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

    void LinkedDequeue::Enqueue(Element e) {
        auto *new_node = new DoublyNode(e, back_, nullptr);
        if (size_ == 0) {
            front_ = new_node;
            back_ = front_;
        }
        if (size_ > 0) {
            back_->next = new_node;
            back_ = new_node;
        }
        size_++;

        // TODO: напишите здесь свой код ...

    }

    void LinkedDequeue::EnqueueFront(Element e) {
        // TODO: напишите здесь свой код ...
        if (size_ == 0) {
            auto *new_node = new DoublyNode(e, nullptr, nullptr);
            front_ = new_node;
            back_ = front_;
        }
        if (size_ > 0) {
            auto *new_node = new DoublyNode(e, nullptr, front_);
            front_->previous = new_node;
            front_ = new_node;
        }
        size_++;
    }

    void LinkedDequeue::Dequeue() {
        if (size_ == 0) {
            throw std::logic_error("cannot not dequeue from empty queue");
        }
        if (size_ == 1) {
            front_ = nullptr;
            back_ = front_;
        }
        if (size_ > 1) {
            auto* delete_node = front_;
            front_ = front_ -> next;
            delete delete_node;

        }
        size_--;
        // TODO: напишите здесь свой код ...
    }

    void LinkedDequeue::DequeueBack() {
        if (size_ == 0) {
            throw std::logic_error("cannot not dequeue from empty queue");
        }
        if(size_ == 1){
            delete front_;
            front_ = nullptr;
            back_ = front_;
        }
        if(size_ > 1){
            auto* delete_node = back_;
            back_ = back_ ->previous;
            delete delete_node;
            back_->next = nullptr;
        }
        size_--;

        // TODO: напишите здесь свой код ...
    }

    void LinkedDequeue::Clear() {
        for(auto* curr_node = front_; curr_node != nullptr; /*...*/){
            auto* delete_node = curr_node;
            curr_node = curr_node->next;
            delete delete_node;
        }
        size_ = 0;
        back_ = nullptr;
        front_ = nullptr;
        // TODO: напишите здесь свой код ...
    }

// === РЕАЛИЗОВАНО ===

    LinkedDequeue::~LinkedDequeue() {
        Clear();
    }

    std::optional<Element> LinkedDequeue::front() const {
        return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
    }

    std::optional<Element> LinkedDequeue::back() const {
        return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
    }

    bool LinkedDequeue::IsEmpty() const {
        return size_ == 0;
    }

    int LinkedDequeue::size() const {
        return size_;
    }

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

    std::ostream &operator<<(std::ostream &os, const LinkedDequeue &queue) {
        os << "size: " << queue.size_ << '\n';
        for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->previous) {
            if (current_node == queue.front_) os << "[FRONT] ";
            if (current_node == queue.back_) os << "[BACK] ";
            os << enum2str(current_node->data) << '\n';
        }
        return os;
    }

}  // namespace itis
