#include <queue>
#include <variant>
#include <absl/types/variant.h>

using message_type = int;

namespace using_CRTP_and_variants {
template <typename T>
struct actor {
  void update() { as_underlying().update(); }

  void handle_all_messages() {
    while (!pending_messages.empty()) {
      auto message = std::move(pending_messages.front());
      pending_messages.pop();
      handle_one_message(std::move(message));
    }
  }

  void receive_message(message_type&& msg) {
    pending_messages.emplace(std::forward<message_type>(msg));
  }

 private:
  friend T;
  actor() = default;

  std::queue<message_type> pending_messages;

  inline T& as_underlying() { return static_cast<T&>(*this); }

  void handle_one_message(message_type&& msg) {
    as_underlying().handle_one_message(std::forward<message_type>(msg));
  }
};

struct A : actor<A> {
  using actor::actor;

  void update() { /* impl ...*/
  }

 private:
  friend struct actor<A>;

  void handle_one_message(message_type&& msg) { /* impl ...*/
  }
};

struct B : actor<B> {
  using actor::actor;

  void update() { /* impl ...*/
  }

 private:
  friend struct actor<B>;

  void handle_one_message(message_type&& msg) { /* impl ...*/
  }
};
}  // namespace using_CRTP_and_variants

template <typename... Ts>
using poly_T = std::variant<Ts...>;

using container_type = std::vector<
    poly_T<using_CRTP_and_variants::A, using_CRTP_and_variants::B> >;

void func() {
  container_type actors{
      using_CRTP_and_variants::A{}, using_CRTP_and_variants::B{},
      using_CRTP_and_variants::A{}
      /* etc */
  };

  actors.emplace_back(using_CRTP_and_variants::A{});
  actors.emplace_back(using_CRTP_and_variants::B{});
}
